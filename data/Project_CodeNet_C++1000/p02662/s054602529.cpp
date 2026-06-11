#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

const int MOD = 998244353;

int power(int a, int b) {
	if (b == 0) return 1;
	int result = power(a, b / 2);
	return (LL) result * result % MOD * (b % 2 == 1 ? a : 1) % MOD;
}

void solve_test() {
	int n, s;
	cin >> n >> s;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	vector<vector<int>> dp(n + 1, vector<int>(s + 1));
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= s; j++) {
			dp[i][j] = dp[i - 1][j] * 2 % MOD;
			if (j >= a[i - 1])
				dp[i][j] = (dp[i][j] + dp[i - 1][j - a[i - 1]]) % MOD;
		}
	}
	cout << dp[n][s] << '\n';
}

int main() {
	int T;
	T = 1;
	for (int t = 1; t <= T; t++)
		solve_test();

	return 0;
}
