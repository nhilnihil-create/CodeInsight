#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

int32_t main() {
	int n;
	cin >> n;
	int ans = 1;
	if (n == 1) {
		cout << 0;
		return 0;
	}
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, 0)));
	dp[0][1][0] = 1;
	dp[0][0][1] = 1;
	dp[0][0][0] = 8;
	for (int i = 1; i < n; ++i) {
		dp[i][0][0] = dp[i - 1][0][0] * 8;
		dp[i][0][0] %= mod;
		dp[i][1][0] = dp[i - 1][1][0] * 9 + dp[i - 1][0][0];
		dp[i][1][0] %= mod;
		dp[i][0][1] = dp[i - 1][0][1] * 9 + dp[i - 1][0][0];
		dp[i][0][1] %= mod;
		dp[i][1][1] = dp[i - 1][1][1] * 10 + dp[i - 1][1][0] + dp[i - 1][0][1];
		dp[i][1][1] %= mod;
	}
	cout << dp[n - 1][1][1];
}