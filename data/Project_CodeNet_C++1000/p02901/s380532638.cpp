#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
using P = pair<ll, ll>;
using V = vector<ll>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i, n) for(ll i=1;i<=(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define MOD 1000000007
#define INF 1000000000
#define LLINF 1e18

template<class T>bool chmax(T & a, const T & b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T & a, const T & b) { if (b < a) { a = b; return 1; } return 0; }

void solve_abc_e() {
	ll n, m, l;
	cin >> n >> m;

	V a(m), b(m), c(m);
	rep(i, m) {
		cin >> a[i] >> b[i];
		ll tmp = 0;
		rep(j, b[i]) {
			cin >> tmp;
			c[i] |= 1 << (tmp - 1);
		}
	}

	V dp(1 << n, LLINF);
	dp[0] = 0;

	rep(i, 1 << n) {
		rep(j, m) {
			ll t = i | c[j];
			ll cost = dp[i] + a[j];
			chmin(dp[t], cost);
		}
	}

	if (dp[(1 << n) - 1] != LLINF) {
		cout << dp[(1 << n) - 1] << "\n";
	}
	else {
		cout << -1 << "\n";
	}
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	solve_abc_e();

	return 0;
}