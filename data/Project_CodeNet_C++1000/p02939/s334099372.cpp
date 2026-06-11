#include <stdio.h>
char s[200005];
int dp[200005][4];
int d;
int x;
int y;
int ans;
int main() {
	for (int i = 0; i < 200005; i++) {
		s[i] = '1';
	}
	scanf("%s", s);
	for (int i = 0; i < 200005; i++) {
		if (s[i] != '1')d = i;
	}
	dp[0][0] = 1;
	for (int i = 1; i < d; i++) {
		for (int j = 0; j < 4; j++) {
			if (i >= j) {
				if (i == j)dp[i][j] = 1;
				else {
					x = 0;
					for (int k = 0; k < 4; k++) {
						if (k + j < i) {
							if (k == j) {
								y = 0;
								for (int l = 0; l <= k; l++) {
									if (s[i - l] != s[i - l - j - 1])y = 1;
								}
								if (y && dp[i - j - 1][k] > x)x = dp[i - j - 1][k];
							}
							else {
								if (dp[i - j - 1][k] > x)x = dp[i - j - 1][k];
							}
						}
					}
					dp[i][j] = x + 1;
				}
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		if (dp[d - 1][i] > ans)ans = dp[d - 1][i];
	}
	printf("%d\n", ans);
}
