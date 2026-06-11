#include <bits/stdc++.h>

template <typename T>
void update(T &x, const T &y) {
	if (x > y) x = y;
}

const int MAX_N = 110, INF = 0x3f3f3f3f;

int n, m;
char s[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s[i] + 1);
	}

	dp[1][1] = s[1][1] == '#';
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (i == 1 && j == 1)
				continue;
			dp[i][j] = INF;
			if (i > 1) {
				if (s[i - 1][j] == s[i][j])
					update(dp[i][j], dp[i - 1][j]);
				else
					update(dp[i][j], dp[i - 1][j] + (s[i][j] == '#'));
			}
			if (j > 1) {
				if (s[i][j - 1] == s[i][j])
					update(dp[i][j], dp[i][j - 1]);
				else
					update(dp[i][j], dp[i][j - 1] + (s[i][j] == '#'));	
			}
		}
	}
	printf("%d\n", dp[n][m]);
}