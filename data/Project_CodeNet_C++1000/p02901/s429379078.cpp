#include <bits/stdc++.h>
using namespace std;

//https://atcoder.jp/contests/abc142/tasks/abc142_e

const int mm = 1e3, infty = 1e9;

int n, m;
int dp[4096];
pair<int, int> key[mm];

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, c, d = 0;
		cin >> a >> b;
		for (int j = 0; j < b; ++j) {
			cin >> c;
			d |= 1 << c - 1;
		}
		key[i] = make_pair(a, d);
	}

	fill(dp + 1, dp + 4096, infty);

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < 4095; ++j)
			dp[j | key[i].second] = min(dp[j | key[i].second],
					dp[j] + key[i].first);

	cout << (dp[(1 << n) - 1] < infty ? dp[(1 << n) - 1] : -1) << endl;

}
