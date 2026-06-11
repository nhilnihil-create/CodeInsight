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
	int N, K;
	cin >> N >> K;
	
	vector<int> P(N), C(N);
	REP(i, N) scanf("%d", &P[i]), --P[i];
	REP(i, N) scanf("%d", &C[i]);
	
	vector<bool> done(N);
	ll ans = -longINF;
	
	REP(s, N) {
		if (done[s]) continue;
		
		vector<int> cycle;
		auto dfs = [&](auto dfs, int x) {
			if (done[x]) return;
			done[x] = true;
			cycle.emplace_back(x);
			dfs(dfs, P[x]);
		};
		dfs(dfs, s);
		
		int sz = cycle.size();
		
		ll loopsum = 0;
		REP(i, sz) loopsum += C[P[cycle[i]]];
		
		REP(i, sz) {
			ll cur = 0;
			int p = cycle[i];
			
			REP(j, sz + 1) {
				if (j > 0) {
					if (j > K) continue;
					if (loopsum > 0) chmax(ans, cur + (K - j) / sz * loopsum);
					else chmax(ans, cur);
				}
				p = P[p];
				cur += C[p];
			}
		}
	}
	cout << ans << endl;
	return 0;
}
