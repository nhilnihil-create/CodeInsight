#include <algorithm>
#include <stdio.h>
using namespace std;
using ll = long long;

int n, m, s[2010], t[2010];
ll dp[2010][2010];
const ll mod = 1e9 + 7;
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", s + i);
	for (int i = 1; i <= m; i++)
		scanf("%d", t + i);

	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
		dp[i][0] = 1;
	for (int i = 1; i <= m; i++)
		dp[0][i] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + (s[i] == t[j] ? dp[i - 1][j - 1] : 0)) % mod;
			if (dp[i][j] < 0)
				dp[i][j] += mod;
		}
	printf("%lld\n", dp[n][m]);
}