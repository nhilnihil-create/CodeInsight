#include <bits/stdc++.h>
using namespace std;
// typedef
using ll  = long long;
using str = string;
using PL  = pair<ll, ll>;
using P   = pair<int, int>;
using VL  = vector<ll>;
using VI  = vector<int>;
using VS  = vector<str>;
using VP  = vector<P>;
using VPL = vector<PL>;
using VVL = vector<VL>;
using VVI = vector<VI>;

// const num
const ll INF         = 1e18 + 18;
const ll MAX         = 100005;
const ll MOD         = 1000000007;
const long double PI = acosl(-1.0);

// loop
#define REP(i, a, b) for(ll(i) = (a); (i) < (b); (i)++)
#define RREP(i, a, b) for(ll(i) = (a); (i) >= (b); (i)--)
#define rep(i, n) REP(i, 0, n)
#define rrep(i, n) RREP(i, n, 0)

// YesNo
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl
#define YES(n) cout << ((n) ? "YES" : "NO") << endl
// All
#define ALL(v) v.begin(), v.end()
#define deduplicate(v) (v).erase(unique(ALL(d)), (v).end())

int main(void) {
	int n, m;
	cin >> n >> m;
	int p;
	str s;
	int penalty  = 0;
	int answered = 0;
	vector<bool> AC(n + 1, false);
	VI WA(n + 1, false);
	rep(i, m) {
		cin >> p >> s;
		if(!AC[p] && s == "AC") {
			AC[p] = true;
			answered++;
			penalty += WA[p];
		}
		if(!AC[p] && s == "WA") {
			WA[p]++;
		}
	}
	cout << answered << ' ' << penalty << endl;
	return 0;
}