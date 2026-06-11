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
// #define MOD 1000000007
#define MOD 998244353
#define VL vector<ll>

vector<ll> dx = {-1, 1, 0, 0};
vector<ll> dy = {0, 0, 1, -1};

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }



int main()
{
	ll N, K;
	cin >> N >> K;
	ll t = ((N-1)*(N-2))/2;
	vector<P> ans;
	REP(i, N-1) {
		ans.push_back(P(1, i+2));
	}

	if (t == K) {
		PRINT(ans.size());
	REP(i, ans.size()) {
		PRINT(ans[i].first << " " << ans[i].second);
	}
	return 0;
	}
	FOR(i, 2, N+1) {
		FOR(j, i+1, N+1) {
			ans.push_back(P(i, j));
			t--;
			if (t == K) {
				i = N;
				j = N;
			}
		}
	}
	if (t != K) {
		PRINT(-1);
		return 0;
	}
	PRINT(ans.size());
	REP(i, ans.size()) {
		PRINT(ans[i].first << " " << ans[i].second);
	}

	return 0;
}
