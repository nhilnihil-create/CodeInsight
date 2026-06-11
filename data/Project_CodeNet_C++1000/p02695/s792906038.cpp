#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string.h>
#include<iomanip>
using namespace std;

#define PI 3.14159265358979323846264338327950L

void comb(int n, int k, int p, int q, vector<int> v, vector<vector<int>> &w, int *cnt) {
	if (n == p && k == q) *cnt = 0;
	if (w.size() == *cnt) w.resize(w.size() + 10000);
	if (q == 0) {
		w.at(*cnt) = v;
		*cnt += 1;
		return;
	}
	if (p == q) {
		w.at(*cnt) = v;
		for (int jj = n - p + 1; jj <= n; jj++) {
			w.at(*cnt).push_back(jj);
		}
		*cnt += 1;
		return;
	}
	comb(n, k, p - 1, q, v, w, cnt);
	v.push_back(n - p + 1);
	comb(n, k, p - 1, q - 1, v, w, cnt);
	return;
}

int main() {
	int N, M, Q;
	int l[50][4];

	cin >> N >> M >> Q;
	for (int ii = 0; ii < Q; ii++) {
		for (int jj = 0; jj < 4; jj++) {
			cin >> l[ii][jj];
		}
	}
	vector<int> v;
	vector<vector<int>> w(100, vector<int>());
	int cnt, sum = 0;
	comb(N + M - 1, N, N + M - 1, N, v, w, &cnt);
	for (int ii = 0; ii < cnt; ii++) {
		int tmp = 0;
		for (int jj = 0; jj < N; jj++) {
			w.at(ii).at(jj) -= jj;
		}
		for (int jj = 0; jj < Q; jj++) {
			if (w.at(ii).at(l[jj][1] - 1) - w.at(ii).at(l[jj][0] - 1) == l[jj][2]) {
				tmp += l[jj][3];
			}
		}
		if (tmp > sum) {
			sum = tmp;
		}
	}
	cout << sum << endl;
	return 0;
}