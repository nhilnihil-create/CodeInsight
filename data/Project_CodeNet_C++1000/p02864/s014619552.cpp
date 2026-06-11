//高さを0にもできることに注意！！！！
#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i, n) for(i = 0; i < n; i++)
#define int long long
using namespace std;

void chmin(int &a, int b) { a = min(a, b); }

int INF = 1e+13;
int n, K;
int h[301];
vector<int> sortH;
int ordH[301];
int dp[302][302][302];	//dp[i][j][k] = i個見た. 最後の高さはsortH[j]. k回変更.

signed main() {
	int i, j, k;
	
	cin >> n >> K;
	h[0] = 0;
	rep(i, n) cin >> h[i + 1];
	sortH.push_back(h[0]);
	rep(i, n) sortH.push_back(h[i + 1]);
	sort(sortH.begin(), sortH.end());
	sortH.erase(unique(sortH.begin(), sortH.end()), sortH.end());
	n = n + 1;
	
	rep(i, n) ordH[i] = lower_bound(sortH.begin(), sortH.end(), h[i]) - sortH.begin();
	
	rep(i, n + 1) rep(j, n) rep(k, K + 1) dp[i][j][k] = INF;
	dp[0][0][0] = 0;
	
	for (i = 0; i < n; i++) {
		rep(j, n) {
			rep(k, K + 1) {
				if (dp[i][j][k] >= INF) continue;
				//h[i]を変更しない
				chmin(dp[i + 1][ordH[i]][k], dp[i][j][k] + h[i] - min(h[i], sortH[j]));
				//h[i]をsortH[j]に変更する
				if (k + 1 <= K) chmin(dp[i + 1][j][k + 1], dp[i][j][k]);
			}
		}
	}
	
	int ans = INF;
	rep(j, n) rep(k, K + 1) chmin(ans, dp[n][j][k]);
	cout << ans << endl;
	return 0;
}