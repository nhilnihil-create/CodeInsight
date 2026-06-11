#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) begin(v),end(v)
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
using ll = long long;
using pii = pair<int, int>;
constexpr ll INF = 1ll<<30;
constexpr ll longINF = 1ll<<60;
constexpr ll MOD = 1000000007;
constexpr bool debug = 0;
//---------------------------------//

int N, K;
int H[301];
ll dp[301][301];

int main() {
	cin >> N >> K;
	REP(i, N) scanf("%d", H + i + 1);
	
	fill(dp[0], dp[N + 1], longINF);
	dp[0][0] = 0;
	REP(i, N) REP(j, N - K + 1) {
		if (dp[i][j] == longINF) continue;
		FOR(k, i + 1, N + 1) {
			chmin(dp[k][j + 1], dp[i][j] + max(0, H[k] - H[i]));
		}
	}
	
	ll ans = longINF;
	REP(i, N + 1) chmin(ans, dp[i][N - K]);
	cout << ans << endl;
	return 0;
}
