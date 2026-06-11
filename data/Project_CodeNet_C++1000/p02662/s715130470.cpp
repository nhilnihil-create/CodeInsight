#include <iostream>
using namespace std;
const int MAX = 3000;
const int MOD = 998244353;

long long mod(long long a) {
	a %= MOD;
	return a >= 0 ? a : a+MOD;
}

int main() {
	int n, s;
	cin >> n >> s;
	long long dp[MAX+1] = {};
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;
		for (int j = s; j >= 0; j--) {
			dp[j] = mod(dp[j] * 2);
			if (j - a >= 0) dp[j] = mod(dp[j] + dp[j-a]);
		}
	}
	long long ans = dp[s];
	cout << ans << endl;
	return 0;
}