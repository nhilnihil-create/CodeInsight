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
	
	ll ans = 0;
	REP(t, 112345) {
		double angle = t * 2*M_PI/112345.0;
		double X = cos(angle), Y = sin(angle);
		int curx = 0, cury = 0;
		REP(i, N) {
			if (X * x[i] + Y * y[i] >= EPS) {
				curx += x[i];
				cury += y[i];
			}
			chmax(ans, calc(curx, cury));
		}
	}
	printf("%.15lf\n", sqrt(ans));
	
	
	return 0;
}
