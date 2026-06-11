#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
long long dp[1000010][2][2];
const long long mod = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	dp[1][0][0] = 8;
	dp[1][1][0] = 1;
	dp[1][0][1] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				dp[i + 1][j][k] = (dp[i + 1][j][k] + dp[i][j][k] * 8) % mod;
				dp[i + 1][j | 1][k] = (dp[i + 1][j | 1][k] + dp[i][j][k]) % mod;
				dp[i + 1][j][k | 1] = (dp[i + 1][j][k | 1] + dp[i][j][k]) % mod;
			}
		}
	}
	cout << dp[n][1][1];
	return 0;
}