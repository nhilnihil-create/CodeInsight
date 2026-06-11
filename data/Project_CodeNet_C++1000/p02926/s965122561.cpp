#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, pii> pip;
typedef pair<pll, pll> P;
const ll INF = 1ll<<30;
const ll MOD = 1000000007;
const double EPS = 1e-9;
const bool debug = 0;
//---------------------------------//

int N;
int x[100], y[100];

ll calc(ll a, ll b) {
	return a * a + b * b;
}

int main() {
	cin >> N;
	REP(i, N) scanf("%d %d", x + i, y + i);
	
	vector<pair<double, int> > v;
	REP(i, N) {
		v.push_back(make_pair(atan2(y[i], x[i]), i));
		v.push_back(make_pair(v.back().fi + 2*M_PI, i));
	}
	sort(ALL(v));
		
	ll ans = 0;
	REP(i, N) {
		ll sumx = 0, sumy = 0;
		FOR(j, i, i + N) {
			int u = v[j].se;
			sumx += x[u];
			sumy += y[u];
			chmax(ans, calc(sumx, sumy));
		}
	}
	
	printf("%.15lf\n", sqrt(ans));
	
	return 0;
}

