#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long int
using namespace std;
int mod = 1e9 + 7;

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;

	int n;
	cin >> n;
	int dp[n + 1];
	memset(dp, 0, sizeof dp);
	for (int i = 0; i <= n; i++) {
		if (i >= 3)
			dp[i] = 1;
		for (int j = 0; j <= i - 3; j++)
			dp[i] += dp[j] % mod;
	}
	cout << dp[n] % mod;
	return 0;
}