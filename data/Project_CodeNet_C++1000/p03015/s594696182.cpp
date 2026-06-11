#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using ll = long long;
const ll mod = 1e9 + 7;
char c[100005];
ll dp[100005][2];
int main() {
	scanf("%s", c);
	int n = strlen(c);
	dp[0][0] = 1, dp[0][1] = 2;
	repl(i, 1, n) {
		if (c[i] == '1') {
			dp[i][0] = dp[i - 1][0] * 3 + dp[i - 1][1];
			dp[i][1] = dp[i - 1][1] * 2;
		} else {
			dp[i][0] = dp[i - 1][0] * 3;
			dp[i][1] = dp[i - 1][1];
		}
		dp[i][0] %= mod;
		dp[i][1] %= mod;
	}
	printf("%lld\n", (dp[n - 1][0] + dp[n - 1][1]) % mod);
	return 0;
}
