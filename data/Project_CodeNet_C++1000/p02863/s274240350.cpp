#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

const int maxn = 3013, maxt = 3013;

int n, t;
int dp[maxn][maxt];
pair < int, int > d[maxn];

void ckmax (int &a, int b) {
	a = max(a, b);
}

signed main () {
	cin >> n >> t;
	for (int i = 1; i <= n; ++i)
		cin >> d[i].x >> d[i].y;
	sort(d + 1, d + n + 1);
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < t; ++j) {
			ckmax(dp[i][j], dp[i - 1][j]);
			ckmax(dp[i][min(t, j + d[i].x)], dp[i - 1][j] + d[i].y);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= t; ++j)
			ckmax(ans, dp[i][j]);
	}
	cout << ans << '\n';
}
