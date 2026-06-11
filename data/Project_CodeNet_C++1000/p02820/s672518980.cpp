#include <iostream>
#include<iomanip>
#include <string>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
#include<math.h>
#include<stack>
#include<set>
#include<map>
#define INF long long int(1e18+1)
#define rep(i,n,m) for(int i=n;i<m;i++)

using namespace std;

long long int dp[3][100010];

int main()
{
	int n, k;
	cin >> n >> k;
	int r, s, p;
	cin >> r >> s >> p;
	string t;
	cin >> t;

	rep(i, 0, 3)dp[i][0] = 0;
	rep(j, 1, n + 1) {
		long long int m;
		if (t[j - 1] == 'r') {
			dp[0][j] = dp[0][j - 1];
			dp[1][j] = dp[1][j - 1];
			if (j - k > 0)
				if (dp[2][j - k] != dp[2][j - k - 1]) {
					dp[2][j] = dp[2][j - 1];
					continue;
				}
			m = max(dp[0][j - 1], dp[1][j - 1]);
			m = max(m, dp[2][j - 1]);
			dp[2][j] += m + p;
		}
		else if (t[j - 1] == 's') {
			dp[1][j] = dp[1][j - 1];
			dp[2][j] = dp[2][j - 1];
			if (j - k > 0)
				if (dp[0][j - k] != dp[0][j - k - 1]) {
					dp[0][j] = dp[0][j - 1];
					continue;
				}
			m = max(dp[1][j - 1], dp[2][j - 1]);
			m = max(m, dp[0][j - 1]);
			dp[0][j] += m + r;
		}
		else if (t[j - 1] == 'p') {
			dp[0][j] = dp[0][j - 1];
			dp[2][j] = dp[2][j - 1];
			if (j - k > 0)
				if (dp[1][j - k] != dp[1][j - k - 1]) {
					dp[1][j] = dp[1][j - 1];
					continue;
				}
			m = max(dp[0][j - 1], dp[2][j - 1]);
			m = max(m, dp[1][j - 1]);
			dp[1][j] += m + s;
		}
	}
		long long int ans = 0;
		rep(i, 0, 3)ans = max(ans, dp[i][n]);
		cout << ans << endl;
}

