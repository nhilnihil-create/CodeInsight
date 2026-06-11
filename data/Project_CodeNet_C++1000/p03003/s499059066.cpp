#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

signed main () {
	int n, m;
	cin >> n >> m;
	vector < int > s(n), t(m);
	for (int &x: s)
		cin >> x;
	for (int &x: t)
		cin >> x;
	vector < vector < int > > dp(n + 1, vector < int > (m + 1, 0));
	for (int i = 0; i <= n; ++i)
		dp[i][0] = 1;
	for (int i = 0; i <= m; ++i)
		dp[0][i] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
			if (s[i - 1] != t[j - 1])
				dp[i][j] = (dp[i][j] + mod - dp[i - 1][j - 1]) % mod;
		}
	}
	cout << dp[n][m] << '\n';
}
