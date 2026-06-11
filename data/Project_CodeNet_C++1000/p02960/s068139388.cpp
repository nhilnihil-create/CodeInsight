#include <iostream>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;

long long mod(long long a) {
	a %= MOD;
	return a >= 0 ? a : a+MOD;
}
long long mod(long long a, long long m) {
	a %= m;
	return a >= 0 ? a : a+m;
}

int main() {
	string s;
	cin >> s;
	int n = s.size();
	reverse(s.begin(), s.end());

	long long dp[n+1][13];
	fill((long long *)dp, (long long *)dp + sizeof(dp)/sizeof(long long), 0);
	dp[0][0] = 1;
	long long z = 1;
	for (int i = 0; i < n; i++) {
		int D = s[i]=='?' ? -1 : s[i] - '0';
		for (int j = 0; j < 13; j++) {
			if (D == -1) {
				for (int x = 0; x < 10; x++) {
					int next_j = mod(j+z*x,13);
					dp[i+1][next_j] = mod(dp[i+1][next_j] + dp[i][j]);
				}
			} else {
				int next_j = mod(j+z*D,13);
				dp[i+1][next_j] = mod(dp[i][j] + dp[i+1][next_j]);
			}
		}
		z = mod(z*10, 13);
	}
	long long ans = dp[n][5];
	cout << ans << endl;
	return 0;
}