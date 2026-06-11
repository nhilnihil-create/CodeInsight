#include <iostream>
#include <algorithm>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pl;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int main(void) {
	int n, m, i, j, s[2003], t[2003], dp[2003][2003] = {};

	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%d", &s[i]);
	}
	for (j = 0; j < m; j++) {
		scanf("%d", &t[j]);
	}

	for (i = 0; i <= n; i++) {
		dp[i][0] = 1;
	}
	for (j = 0; j <= m; j++) {
		dp[0][j] = 1;
	}

	for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) {
		dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
		if (s[i - 1] != t[j - 1]) {
			dp[i][j] = (dp[i][j] + mod - dp[i - 1][j - 1]) % mod;
		}
	}

	printf("%d\n", dp[n][m]);

	return 0;
}