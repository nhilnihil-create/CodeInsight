#include<bits/stdc++.h>
using namespace std;
const int maxn = 100 + 7, INF = 1e7;
int n, m, dp[maxn][maxn];
char s[maxn][maxn];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
	for (int i = 0; i <= n + 1; ++i) {
		for (int j = 0; j <= m + 1; ++j) 
			dp[i][j] = INF;
	}
	dp[1][1] = s[1][1] == '#' ? 1 : 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if(i > 1) {
				if(s[i][j] == '#') dp[i][j] = min(dp[i][j],  
							dp[i - 1][j] + (s[i - 1][j] == '#'? 0 : 1));
				else dp[i][j] = min(dp[i][j], dp[i - 1][j]);
			}
			if(j > 1) {
				if(s[i][j] == '#') dp[i][j] = min(dp[i][j], 
							dp[i][j - 1] + (s[i][j - 1] == '#'? 0 : 1));
				else dp[i][j] = min(dp[i][j], dp[i][j - 1]); 
			}
		}
	}
	printf("%d\n", dp[n][m]);
	return 0;
}