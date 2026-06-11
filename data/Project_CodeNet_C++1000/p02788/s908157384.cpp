#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;
#define REP(i, n) for(ll i = 0LL; i < (ll)(n); i++)
#define REPR(i, n) for(ll i = n-1; i >= 0LL; i--)
#define FOR(i, n, m) for(ll i = n; i < (ll)(m); i++)
#define PRINT(x) cout << x << endl
#define ALL(v) v.begin(), v.end()
#define INF (ll)1e18
#define INFD 1e18
#define PI 3.14159265358979
#define MOD 1000000007
// #define MOD 998244353
#define VL vector<ll>

vector<ll> dx = {-1, 1, 0, 0};
vector<ll> dy = {0, 0, 1, -1};

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main()
{
	ll N, D, A;
	cin >> N >> D >> A;
	vector<P> v(N);
	REP(i, N) {
		ll X, H;
		cin >> X >> H;
		v[i] = P(X, H);
	}
	sort(ALL(v));
	v.push_back(P(INF, 0));
	vector<ll> u(N+1);
	ll ans = 0;
	REP(i, N) {
		if (v[i].second - A * u[i] > 0) {
			ll tmp = ((v[i].second - A * u[i])+A-1) / A;
			auto iter = upper_bound(ALL(v), P(v[i].first + 2*D, INF));
			ll ind = distance(v.begin(), iter);
			u[i] += tmp;
			u[ind] -= tmp;
			ans += tmp;
		}
		u[i+1] += u[i];
		// REP(i, N+1) cout << u[i] << " ";
		// cout << endl;
	}
	// REP(i, N+1) cout << u[i] << " ";
	// cout << endl;
	PRINT(ans);
	return 0;
}
