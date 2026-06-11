#include <bits/stdc++.h>
using namespace std;

const int N = 302, K = 302, M = 0;
const long long inf = 1e18;
int n, k, h[N], s[N];
long long dp[N][N][N], pd[N][N][K][2];

void minimize(long long &a, long long b) {
 	a = min(a, b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) {
		cin >> h[i];
		s[i] = h[i];
	}
	sort(s + 1, s + n + 1);
	for(int i = 1; i <= n; ++i) {
		for(int j = M; j <= n; ++j) {
			for(int ii = 0; ii <= k; ++ii) {
				dp[i][j][ii] = inf;
			}
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = M; j <= n; ++j) {
			int gn = (h[i] != s[j] ? 1 : 0);
			for(int ii = 0; ii <= min(i - 1 + gn, k); ++ii) {
				if(ii == 0 && gn == 1) continue;
				dp[i][j][ii] = min(pd[i - 1][j][ii - gn][0] + s[j], (i == 1 ? inf : pd[i - 1][j][ii - gn][1]));
			}
		}
		for(int ii = 0; ii <= k; ++ii) {
			for(int j = M; j <= n; ++j) {
				pd[i][j][ii][0] = dp[i][j][ii] - (dp[i][j][ii] == inf ? 0 : s[j]);
				if(j ^ M)
					minimize(pd[i][j][ii][0], pd[i][j - 1][ii][0]);
			}
			for(int j = n; j >= M; --j) {
				pd[i][j][ii][1] = dp[i][j][ii];
				if(j ^ n)
					minimize(pd[i][j][ii][1], pd[i][j + 1][ii][1]);
			}
		}
	}
	long long fp = pd[n][M][0][1];
	for(int ii = 0; ii <= k; ++ii) {
		minimize(fp, pd[n][M][ii][1]);
	}
	cout << fp << endl;
	return 0;
}
