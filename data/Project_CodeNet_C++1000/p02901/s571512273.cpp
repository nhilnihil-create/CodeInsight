#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9 + 13;

void ckmin (int &x, int a) {
	x = min(x, a);
}

signed main () {
	int n, m;
	cin >> n >> m;
	vector < int > a(m + 1), c(m + 1, 0);
	for (int i = 1; i <= m; ++i) {
		int b, w;
		cin >> a[i] >> b;
		for (int j = 0; j < b; ++j) {
			cin >> w;
			c[i] += (1 << (w - 1));
		}
	}
	int dp[m + 1][(1 << n)];
	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j < (1 << n); ++j) 
			dp[i][j] = inf;
	}
	dp[0][0] = 0;
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < (1 << n); ++j)
			dp[i][j] = dp[i - 1][j];
		for (int j = 0; j < (1 << n); ++j) 
			ckmin(dp[i][(j | c[i])], dp[i - 1][j] + a[i]);
	}
	if (dp[m][(1 << n) - 1] == inf)
		cout << -1 << '\n';
	else
		cout << dp[m][(1 << n) - 1] << '\n';
}
