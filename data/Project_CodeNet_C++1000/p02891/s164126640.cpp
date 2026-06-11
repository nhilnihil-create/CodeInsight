#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second

#define N 1514

int n, K;
char s[N];
int dp[N][26];

int main() {
	scanf("%s%d", s, &K);
	n = int(strlen(s));
	bool all = 1;
	for (int i = 1; i < n; i++) all &= s[i] == s[i - 1]; 
	if (all) {
		cout << LL(n) * K / 2 << endl;
		return 0;
	}
	int R = min(K, 5), m = R * n;
	for (int i = 1; i < R; i++) for (int j = 0; j < n; j++) s[i * n + j] = s[(i - 1) * n + j];
	memset(dp, 0x3f, sizeof dp);
	for (int i = 0 ;i < 26; i++) dp[0][i] = (s[0] - 'a' != i);
	for (int i = 1; i < m; i++) {
		int x = s[i] - 'a';
		for (int j = 0; j < 26; j++) {
			for (int k = 0; k < 26; k++) if (j != k){
				dp[i][k] = min(dp[i][k], dp[i - 1][j] + (k != x));
			}
		}
	}
	if (R == K) {
		int ans = 0x3f3f3f3f;
		for (int i = 0; i < 26; i++) ans = min(ans, dp[m - 1][i]); 
		cout << ans << endl;
	}
	else {
		int ans1 = 0x3f3f3f3f, ans2 = 0x3f3f3f3f;
		for (int i = 0; i < 26; i++) ans1 = min(ans1, dp[m - 1][i]); 
		for (int i = 0; i < 26; i++) ans2 = min(ans2, dp[m - n - 1][i]); 
		long long ans = LL(ans2 - ans1) * (R - K) + ans1;
		cout << ans << endl;
	}
}
