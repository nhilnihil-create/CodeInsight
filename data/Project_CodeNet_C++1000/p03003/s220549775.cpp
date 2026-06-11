#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

const int MOD = 1e9 + 7;

int add(int &x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
}

int main(int argc, char **argv) {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < m; ++i)
		cin >> b[i];

	vector<vector<int>> dp(n + 1, vector<int>(m + 1));
	for (int i = 0; i < m; ++i)
		dp[n][i] = 1;
	for (int i = 0; i < n; ++i)
		dp[i][m] = 1;
	dp[n][m] = 1;
	for (int i = n - 1; i >= 0; --i)
		for (int j = m - 1; j >= 0; --j) {
			if (a[i] == b[j])
				dp[i][j] = dp[i + 1][j + 1];
			add(dp[i][j], dp[i + 1][j]);
			add(dp[i][j], dp[i][j + 1]);
			add(dp[i][j], MOD - dp[i + 1][j + 1]);
		}

	cout << dp[0][0] << '\n';
	return 0;
}
