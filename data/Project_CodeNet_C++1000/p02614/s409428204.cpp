#include "bits/stdc++.h"
using namespace std;

#define ll long long

int main() {
	int h, w, k;
	int h1, w1;
	int h2, w2;
	int i, j;
	int q1, q2;
	int buf;
	int cc;
	int kc = 0;
	int count = 0;
	cin >> h >> w >> k;
	char c;
	vector<vector<int>> s(h);
	vector<int> h_num(h);
	vector<int> h_buf;
	vector<int> w_num(w);
	vector<int> w_buf;
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			cin >> c;
			if (c == '.')buf = 0;
			else {
				buf = 1;
				kc++;
				h_num[i]++;
				w_num[j]++;
			}
			s[i].push_back(buf);
		}
	}
	h2 = (int)pow(2.0, h);
	w2 = (int)pow(2.0, w);
	for (i = 0; i < h2; i++){
		for (j = 0; j < w2; j++) {
			h1 = i;
			w1 = j;
			buf = kc;
			cc = 0;
			while (h1 > 0) {
				if (h1 % 2 == 1) {
					buf -= h_num[cc];
					h_buf.push_back(cc);
					
				}
				h1 /= 2;
				cc++;
			}
			cc = 0;
			while (w1 > 0) {
				if (w1 % 2 == 1) {
					buf -= w_num[cc];
					w_buf.push_back(cc);
					
				}
				w1 /= 2;
				cc++;
			}
			for (q1 = 0; q1 < h_buf.size(); q1++) {
				for (q2 = 0; q2 < w_buf.size(); q2++) {
					if (s[h_buf[q1]][w_buf[q2]] == 1)buf++;
				}
			}
			if (buf == k)count++;
			h_buf.clear();
			w_buf.clear();
		}
	}
	cout << count << endl;
	return 0;
}