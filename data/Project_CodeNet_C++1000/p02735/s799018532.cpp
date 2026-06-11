#include <bits/stdc++.h>

using namespace std;

const int maxn = 110;

int n, m;
int dp[maxn][maxn];
char str[maxn][maxn];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", str[i] + 1);
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[1][1] = (str[1][1] == '#');
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i > 1) dp[i][j] = min(dp[i][j], dp[i-1][j] + (str[i][j] == '#' && str[i-1][j] == '.'));
			if (j > 1) dp[i][j] = min(dp[i][j], dp[i][j-1] + (str[i][j] == '#' && str[i][j-1] == '.'));
		}
	}
	printf("%d\n", dp[n][m]);
	return 0;
}
