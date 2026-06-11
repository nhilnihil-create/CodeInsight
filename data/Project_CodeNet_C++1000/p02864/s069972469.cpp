#include <bits/stdc++.h>

using namespace std;

long long n, dp[305][305], h[305], ans;
const long long INF = 1e18;
int k;

long long parabs(long long a, long long b) {
	if (a > b) return (a - b);
	else return 0;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i=1; i<305; i++) {
		for (int j=0; j<305; j++) dp[i][j] = INF;
	}
	h[0] = 0; h[n + 1] = 0;
	for (int i=1; i<=n + 1;i++) {
		if (i != n + 1) cin >> h[i];
		for (int j=0; j<=min(k, i - 1); j++) {
			for (int ii = j; ii <= k; ii++) {
				dp[i][ii - j] = min(dp[i][ii - j], dp[i - 1 - j][ii] + parabs(h[i], h[i - j - 1]));
			}
		}
	}
	ans = INF;
	for (int i=0; i<=k; i++) ans = min(ans, dp[n + 1][i]);
//	for (int i=0; i<=9; i++) {
//		for (int j=0; j<=3; j++) {
//			cout << "The value for dp[" << i << "][" << j << "] is " << dp[i][j] << endl;
//		}
//	}
	cout << ans << endl;
}