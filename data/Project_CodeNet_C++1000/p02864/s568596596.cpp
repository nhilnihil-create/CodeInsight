#include <bits/stdc++.h>
using namespace std;

const int N = 305;

int n, k, a[N];

using ll = long long;

const ll inf = 0x3f3f3f3f3f3f3f3f;

ll dp[N][N];

int main() {
	scanf("%d %d", &n, &k);
	if (n == k) {
		puts("0");
		return 0;
	}
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	int up = n-k;
	for (int i = 0; i <= n; i ++) for (int j = 0; j <= up; j ++) dp[i][j] = inf;
	dp[0][0] = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= up; j ++) {
			ll &res = dp[i][j];
			for (int k = 0; k < i; k ++) if (dp[k][j-1] < inf) {
				res = min(res, dp[k][j-1] + (a[k] < a[i] ? a[i] - a[k] : 0));
			}
		}
	}
	ll ans = inf;
	for (int i = 1; i <= n; i ++) ans = min(ans, dp[i][up]);
	cout << ans << endl;
	return 0;
}
