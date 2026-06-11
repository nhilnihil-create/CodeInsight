#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

long long mod = 998244353;
long long N, S;
long long A[1 << 18];
long long dp[3009][3009];

int main() {
	cin >> N >> S;
	for (int i = 1; i <= N; i++) cin >> A[i];
	
	long long val = 1;
	for (int i = 1; i <= N; i++) { val *= 2LL; val %= mod; }

	dp[0][0] = val;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= S; j++) {
			if (dp[i - 1][j] == 0) continue;
			dp[i][j] += dp[i - 1][j];
			dp[i][j] %= mod;
			if (j + A[i] <= S) {
				long long f = dp[i - 1][j]; if (f % 2 == 1) f += mod;
				f /= 2LL;
				dp[i][j + A[i]] += f;
				dp[i][j + A[i]] %= mod;
			}
		}
	}

	cout << dp[N][S] << endl;
	return 0;
}