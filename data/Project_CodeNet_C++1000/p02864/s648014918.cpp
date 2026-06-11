#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <functional>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#define nmax_def 110000
#define Cmax_def 2200
#define mod 1000000007
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Inf 1000000000000000000
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main() {
	int N, K;
	cin >> N >> K;
	vl H(N + 1);
	rep(i, N + 1) {
		if (i == 0) {
			H[0] = 0;
			continue;
		}
		cin >> H[i];
	}
	vector<vector<vl>> dp(N + 1);
	rep(n, N + 1) {
		dp[n].resize(K + 1);
		rep(k, K + 1) {
			dp[n][k].resize(N + 1);
			rep(r, N + 1) {
				dp[n][k][r] = Inf;
			}
		}
	}
	dp[0][0][0] = 0;
	rep(n, N + 1) {
		if (n == 0)
			continue;
		rep(k, K + 1) {
			rep(r, N + 1) {

				// nを操作しない
				ll Hdiff = max(H[n] - H[r], (ll)0);
				dp[n][k][n] = min(dp[n][k][n], dp[n - 1][k][r] + Hdiff);
				
				// nを操作する(左とそろえる)
				if (k == K)
					continue; // 既に上限
				dp[n][k + 1][r] = min(dp[n][k + 1][r], dp[n - 1][k][r]);
			}
		}
	}
	ll ans = Inf;
	rep(k, K + 1) {
		rep(r, N + 1) {
			ans = min(ans, dp[N][k][r]);
		}
	}

	/*rep(n, N + 1) {
		rep(k, K + 1) {
			rep(r, N + 1) {
				cout << n << " " << k << " " << r << " " << dp[n][k][r] << endl;
			}
		}
	}*/
	cout << ans << endl;
	return 0;
}