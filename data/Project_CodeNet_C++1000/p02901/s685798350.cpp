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
	ll N, M;
	cin >> N >> M;
	vector<vector<ll>> v(M);
	REP(i, M) {
		ll a, b;
		cin >> a >> b;
		v[i].push_back(a);
		REP(j, b) {
			ll c;
			cin >> c;
			c--;
			v[i].push_back(c);
		}
	}

	vector<ll> dp(pow(2, N)+1, INF);
	dp[0] = 0;
	REP(i, pow(2, N)+1) {
		ll tmp = 0;
		REP(j, N) {
			if ((i >> j) & 1LL) tmp += pow(2, j);
		}
		REP(j, M) {
			ll ind = tmp;
			REP(k, v[j].size()-1) {
				if (!((tmp >> v[j][k+1]) & 1LL)) ind += pow(2, v[j][k+1]);
			}
			// PRINT(ind);
			dp[ind] = min(dp[ind], dp[i] + v[j][0]);
		}
	}
	// REP(i, pow(2, N)) {
	// 	cout << dp[i] << " ";
	// }
	// cout << endl;
	if (dp[pow(2, N)-1] == INF) {
		PRINT(-1);
	} else {
		PRINT(dp[pow(2, N)-1]);
	}
	return 0;
}
