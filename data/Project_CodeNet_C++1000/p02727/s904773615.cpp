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
	int X, Y, A, B, C;
	cin >> X >> Y >> A >> B >> C;
	vector<int> p(A), q(B), r(C);
	REP(i, A) scanf("%d", &p[i]);
	REP(i, B) scanf("%d", &q[i]);
	REP(i, C) scanf("%d", &r[i]);
	
	sort(ALL(p), greater<int>());
	sort(ALL(q), greater<int>());
	sort(ALL(r), greater<int>());
	
	vector<pii> v;
	REP(i, B) v.emplace_back(q[i], 0);
	REP(i, C) v.emplace_back(r[i], 1);
	sort(ALL(v), greater<pii>());
	
	vector<pii> sum(v.size() + 1, pii(0, 0));
	REP(i, v.size()) {
		sum[i + 1] = sum[i];
		if (v[i].se == 0) ++sum[i + 1].fi;
		else ++sum[i + 1].se;
	}
	vector<ll> sumq(B + 1, 0), sumr(C + 1, 0);
	REP(i, B) sumq[i + 1] = sumq[i] + q[i];
	REP(i, C) sumr[i + 1] = sumr[i] + r[i];
	
	ll ans = 0, curp = 0;
	REP(i, X + 1) {
		ll cur;
		// X + Y - i 個選ぶ
		int scnum = min(X + Y - i, B + C);
		pii sc = sum[scnum];
		if (sc.fi > Y) {
			cur = curp + sumq[Y] + sumr[min(scnum - Y, C)];
		}
		else {
			cur = curp + sumq[sc.fi] + sumr[sc.se];
		}
		
		chmax(ans, cur);
		curp += p[i];
	}
	cout << ans << endl;
}
