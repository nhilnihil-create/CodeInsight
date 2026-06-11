#include <bits/stdc++.h>

using namespace std;
#define MOD 998244353

long long dp[3005][3005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);


	int n, s, x;
	int cnt = 0;
	cin >> n >> s;
	int arr[n+1];
	// long long dp[s+1][n+1];
	// memset(dp, 0, sizeof(long long) * (n+1)*(s+1));
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		arr[i] = x;
	}

	for (int k = 1; k <= n; k++) {
		for (int x = 0; x <= s; x++) {
			dp[x][k] = dp[x][k-1] * 2 % MOD;
			if (x - arr[k] >= 0) dp[x][k] = (dp[x][k] + dp[x-arr[k]][k-1]) % MOD;

		}
	}
	
	cout << dp[s][n] << "\n";
}
