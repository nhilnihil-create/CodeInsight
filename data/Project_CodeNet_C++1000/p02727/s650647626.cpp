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
	
	vector<int> v;
	REP(i, X) v.emplace_back(p[i]);
	REP(i, Y) v.emplace_back(q[i]);
	REP(i, C) v.emplace_back(r[i]);
	sort(ALL(v), greater<int>());
	cout << accumulate(v.begin(), v.begin() + X + Y, 0ll) << endl;
}
