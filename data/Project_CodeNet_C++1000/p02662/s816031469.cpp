#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 3e3 + 5;
const int MOD = 998244353;

int n, s;
int a[N];
ll dp[N][N];

int main() {
	scanf("%d %d", &n, &s);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= s; j++) {
			dp[i][j] = 2 * dp[i - 1][j];
			if (j - a[i] >= 0) dp[i][j] += dp[i - 1][j - a[i]];
			dp[i][j] %= MOD;
		}
	}
	printf("%lld\n", dp[n][s]);
}