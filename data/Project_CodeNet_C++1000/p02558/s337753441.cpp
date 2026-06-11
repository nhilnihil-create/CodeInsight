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

#include <atcoder/dsu>

int main() {
	int N, Q;
	scanf("%d %d", &N, &Q);
	
	atcoder::dsu dsu(N);
	while (Q--) {
		int t, u, v;
		scanf("%d %d %d", &t, &u, &v);
		if (t == 0) dsu.merge(u, v);
		else puts(dsu.same(u, v) ? "1" : "0");
	}
	return 0;
}
