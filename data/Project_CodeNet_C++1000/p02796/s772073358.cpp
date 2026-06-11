#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
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

int main() {
	int N;
	cin >> N;
	vector<int> X(N), L(N);
	REP(i, N) scanf("%d %d", &X[i], &L[i]);
	
	vector<int> cx;
	REP(i, N) cx.emplace_back(X[i] - L[i]);
	REP(i, N) cx.emplace_back(X[i] + L[i]);
	sort(ALL(cx));
	cx.erase(unique(ALL(cx)), cx.end());
	
	vector<vector<int>> g(cx.size());
	REP(i, N) {
		int from = lower_bound(ALL(cx), X[i] - L[i]) - cx.begin();
		int to = lower_bound(ALL(cx), X[i] + L[i]) - cx.begin();
		g[from].emplace_back(to);
	}
	
	vector<int> dp(cx.size() + 1);
	REP(i, cx.size()) {
		chmax(dp[i + 1], dp[i]);
		for (int v : g[i]) chmax(dp[v], dp[i] + 1);
	}
	cout << dp[cx.size()] << endl;
	return 0;
}
