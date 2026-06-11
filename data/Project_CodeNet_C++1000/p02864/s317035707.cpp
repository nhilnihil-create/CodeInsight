#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<string>
#include <iomanip>
#include<math.h>
using namespace std;
typedef long long ll;

int main() {
	ll n, k, i, j, t,u, h[333], dp[301][301][2],ndp[301][301][2],p,ans=1e15;
	cin >> n >> k;
	for (i = 0; i < n; i++)
		cin >> h[i];
	h[n] = 0;
		for (j = 0; j <= k; j++)
			for (t = 0; t <= n; t++)
				for (u = 0; u < 2; u++)
					dp[j][t][u] = -1;
	dp[0][n][0] = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j <= k; j++) {
			for (t = 0; t <= n; t++) {
				for (u = 0; u < 2; u++) {
					ndp[j][t][u] = -1;
				}
			}
		}
		for (j = 0; j <= k; j++) {
			for (t = 0; t <= n; t++) {
				for (u = 0; u < 2; u++) {
					if (dp[j][t][u] >= 0) {
						if (h[i] > h[t]) {
							p = dp[j][t][u] + h[i]-h[t];
							if (ndp[j][i][1] == -1)
								ndp[j][i][1] = p;
							else
								ndp[j][i][1] = min(ndp[j][i][1], p);
							p = dp[j][t][u];
							if (j < k) {
								if (ndp[j+1][t][0] == -1)
									ndp[j+1][t][0] = p;
								else
									ndp[j+1][t][0] = min(ndp[j+1][t][0], p);
							}
						}
						else {
							p = dp[j][t][u];
							if (ndp[j][i][0] == -1)
								ndp[j][i][0] = p;
							else
								ndp[j][i][0] = min(ndp[j][i][0], p);
							p = dp[j][t][u];
							if (j < k) {
								if (ndp[j + 1][t][0] == -1)
									ndp[j + 1][t][0] = p;
								else
									ndp[j + 1][t][0] = min(ndp[j + 1][t][0], p);
							}
						}
					}
				}
			}
		}
		for (j = 0; j <= k; j++) {
			for (t = 0; t <= n; t++) {
				for (u = 0; u < 2; u++) {
					dp[j][t][u] = ndp[j][t][u];
				}
			}
		}
	}
	for (j = 0; j <= k; j++)
		for (t = 0; t <= n; t++)
			for (u = 0; u < 2; u++)
				if(dp[j][t][u]>=0)
					ans = min(ans, dp[j][t][u]);
	cout << ans << endl;
}
