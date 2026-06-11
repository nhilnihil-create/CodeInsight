#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iomanip>
#include <fstream>
#include <thread>

using namespace std;

#define REP(i, n) for(ll i = 0;i < n;i++)
#define REPR(i, n) for(ll i = n;i >= 0;i--)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define REPO(i, n) for(ll i = 1;i <= n;i++)
#define ll long long
#define INF (ll)1 << 60
#define MINF (-1 * INF)
#define ALL(n) n.begin(),n.end()
#define MOD (ll)1000000007
#define P pair<ll, ll>

ll n, m, dp[310][310][310], ans = INF;
int main() {
	REP(i, 310) REP(j, 310) REP(k, 310)dp[i][j][k] = INF;
	cin >> n >> m;
	vector<ll> s(n + 2);
	dp[0][0][0] = 0;
	REPO(i, n)cin >> s[i];
	REPO(i, n + 1) {
		REP(j, m + 1) {
			REP(k, i) {
				//使う場合
				dp[i][j][i] = min(dp[i][j][i], dp[i - 1][j][k] + max(0ll, s[k] - s[i]));
				//使わない場合
				if(i != n + 1) dp[i][j + 1][k] = min(dp[i][j + 1][k], dp[i - 1][j][k]);
			}
		}
	}
	REP(i, m + 1) {
		REP(j, n + 2) {
			ans = min(ans, dp[n + 1][i][j]);
		}
	}
	cout << ans << endl;
}