/*
 sqrtlookup8.inc
 guest openmusiclabs 8.7.12
 sqrt lookup table for 16b unsigned input values
 returns an 8b unsigned value
 this table is optimized for the fft program
 as the max value the sum of 2 squares can return is $8000
 so the top half is truncated off
 and then it is stretched to return 0 - 255
 the table is allocated as follows
 table0 : $000 -> $0ff : sqrt($0000 -> $00ff)
 table2 : $100 -> $17f : sqrt($0100 -> $0fff)
 table1 : $180 -> $27f : sqrt($1000 -> $7fff)

 its hacked to compensate for the $8000 problem

 sample code for doing the lookup table - not tested
 assumes data in z register

 cpi zh,$10
 brsh table2
 cpi zh,$01
 brsh table1
 rjmp done

 table2:

 lsl zl
 rol zh
 mov zl,zh
 ldi zh,$01
 rjmp done

 table1:

 swap zh
 swap zl
 andi zl,$0f
 or zl,zh
 lsr zl
 ldi zh,$02

 done:

 lpm r16,z

*/

0,1,
2,2,
3,3,
3,4,
4,4,
4,5,
5,5,
5,5,
6,6,
6,6,
6,6,
7,7,
7,7,
7,7,
7,8,
8,8,
8,8,
8,8,
8,9,
9,9,
9,9,
9,9,
9,9,
10,10,
10,10,
10,10,
10,10,
10,10,
11,11,
11,11,
11,11,
11,11,
11,11,
11,12,
12,12,
12,12,
12,12,
12,12,
12,12,
12,13,
13,13,
13,13,
13,13,
13,13,
13,13,
13,13,
14,14,
14,14,
14,14,
14,14,
14,14,
14,14,
14,14,
15,15,
15,15,
15,15,
15,15,
15,15,
15,15,
15,15,
15,15,
16,16,
16,16,
16,16,
16,16,
16,16,
16,16,
16,16,
16,16,
17,17,
17,17,
17,17,
17,17,
17,17,
17,17,
17,17,
17,17,
17,18,
18,18,
18,18,
18,18,
18,18,
18,18,
18,18,
18,18,
18,18,
18,19,
19,19,
19,19,
19,19,
19,19,
19,19,
19,19,
19,19,
19,19,
19,19,
20,20,
20,20,
20,20,
20,20,
20,20,
20,20,
20,20,
20,20,
20,20,
20,20,
21,21,
21,21,
21,21,
21,21,
21,21,
21,21,
21,21,
21,21,
21,21,
21,21,
21,22,
22,22,
22,22,
22,22,
22,22,
22,22,
22,22,
22,22,
22,22,
22,22,
22,22,
22,22,
0,8,
11,14,
16,18,
20,21,
23,24,
25,26,
28,29,
30,31,
32,33,
34,35,
36,37,
37,38,
39,40,
41,41,
42,43,
44,44,
45,46,
46,47,
48,48,
49,50,
50,51,
52,52,
53,53,
54,55,
55,56,
56,57,
57,58,
59,59,
60,60,
61,61,
62,62,
63,63,
64,64,
65,65,
66,66,
67,67,
68,68,
69,69,
69,70,
70,71,
71,72,
72,73,
73,73,
74,74,
75,75,
76,76,
76,77,
77,78,
78,78,
79,79,
80,80,
80,81,
81,82,
82,82,
83,83,
84,84,
84,85,
85,85,
86,86,
87,87,
87,88,
88,88,
89,89,
89,90,
255,16,
23,28,
32,36,
39,42,
45,48,
50,53,
55,57,
60,62,
64,66,
68,69,
71,73,
75,76,
78,80,
81,83,
84,86,
87,89,
90,92,
93,94,
96,97,
98,100,
101,102,
103,105,
106,107,
108,109,
110,112,
113,114,
115,116,
117,118,
119,120,
121,122,
123,124,
126,127,
128,129,
129,130,
131,132,
133,134,
135,136,
137,138,
139,140,
141,142,
143,143,
144,145,
146,147,
148,149,
150,150,
151,152,
153,154,
155,155,
156,157,
158,159,
159,160,
161,162,
163,163,
164,165,
166,166,
167,168,
169,169,
170,171,
172,172,
173,174,
175,175,
176,177,
177,178,
179,180,
180,181,
182,182,
183,184,
185,185,
186,187,
187,188,
189,189,
190,191,
191,192,
193,193,
194,195,
195,196,
197,197,
198,198,
199,200,
200,201,
202,202,
203,203,
204,205,
205,206,
207,207,
208,208,
209,210,
210,211,
211,212,
213,213,
214,214,
215,216,
216,217,
217,218,
219,219,
220,220,
221,221,
222,223,
223,224,
224,225,
225,226,
227,227,
228,228,
229,229,
230,230,
231,232,
232,233,
233,234,
234,235,
235,236,
236,237,
237,238,
239,239,
240,240,
241,241,
242,242,
243,243,
244,244,
245,245,
246,246,
247,247,
248,248,
249,249,
250,251,
251,252,
252,253,
253,254,
254,255,
