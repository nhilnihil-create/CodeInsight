#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector <int> a[n+1], dp[n+1];
	a[0].assign(m+1, 0);
	dp[0].assign(m+1, 1e9);
	for (int i=1; i<=n; i++) {
		a[i].assign(m+1, 0);
		dp[i].assign(m+1, 1e9);
		for (int j=1; j<=m; j++) {
			char s;
			cin >> s;
			a[i][j] = (s == '#' ? 1 : 0);
		}
	}
	dp[1][0] = dp[0][1] = 0;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if (a[i][j]) {
				dp[i][j] = min(dp[i-1][j]+(a[i-1][j]?0:1), dp[i][j-1]+(a[i][j-1]?0:1));
			} else {
				dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	cout << dp[n][m];
	return 0;
}
