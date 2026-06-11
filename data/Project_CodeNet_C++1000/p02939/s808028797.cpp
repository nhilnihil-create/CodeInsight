#include <bits/stdc++.h>

const int MAX_N = int(2e5) + 10;
const int INF = 0x3f3f3f3f;

int dp[MAX_N][2];
char s[MAX_N];

int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for (int i = 0; i <= n; ++i) {
		dp[i][0] = dp[i][1] = -INF;
	}
	dp[0][0] = 0;
	dp[1][0] = 1;
	for (int i = 2; i <= n; ++i) {
		dp[i][0] = std::max(dp[i][0], dp[i - 1][1] + 1);
		if (s[i] != s[i - 1])
			dp[i][0] = std::max(dp[i][0], dp[i - 1][0] + 1);
		dp[i][1] = std::max(dp[i][1], dp[i - 2][0] + 1);
		if (i >= 4 && (s[i] != s[i - 2] || s[i - 1] != s[i - 3]))
			dp[i][1] = std::max(dp[i][1], dp[i - 2][1] + 1);
	}
	printf("%d\n", std::max(dp[n][0], dp[n][1]));
}