#include <iostream>
using namespace std;
const int MOD = 1000000007;

long long mod(long long a) {
	a %= MOD;
	return a >= 0 ? a : a+MOD;
}

int main() {
	string s;
	cin >> s;
	long long len = s.size();
	long long dp[len+1][2];
	fill((long long *)dp, (long long *)dp + sizeof(dp)/sizeof(long long), 0);
	dp[0][0] = 1;
	for (int i = 0; i < len; i++) {
		const int D = s[i] - '0';
		if (D == 1) {
			dp[i+1][0] = mod(dp[i][0] * 2);
			dp[i+1][1] = mod(dp[i][0] + dp[i][1]*3);
		} else {
			dp[i+1][0] = dp[i][0];
			dp[i+1][1] = mod(dp[i][1]*3);
		}
	}
	long long ans = mod(dp[len][0] + dp[len][1]);
	cout << ans << endl;
	return 0;
}