#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define pf push_front
#define PI acos(-1)
#define EPS 1e-5
#define sz(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define forn(i, n) for(ll i=0;i<(ll)n;i++)
#define fi first
#define se second
 
const ll MOD = 1e9+7;
const ll MAXN = 2e5+5;

ll mpow(ll x, ll n) {
	ll res = 1;
	while(n != 0) {
		if(n&1) res = res * x % MOD;
		x = x*x % MOD;
		n = n >> 1;
	}
	return res;
}

vector<ll> inv(MAXN);

ll Cnk(ll n, ll k) {
	ll res = 1;
	for(ll i = 1; i <= k; i++) {
		res = res*(n-i+1) % MOD;
	}

	for(ll i = 1; i <= k; i++) {
		res = res*inv[i] % MOD;
	}
	return res;
}

int main() {
	ll n, a, b;
	cin >> n >> a >> b;
	
	for(int i = 1; i <= max(a, b); i++) {
		inv[i] = mpow((ll)i, MOD-2);
	}

	ll ca = Cnk(n, a);
	ll cb = Cnk(n, b);
	ll base = mpow(2, n);
	ll sum = (1+ca+cb) % MOD;
	


	ll ans;
	if(base >= sum) {
		ans = (base - sum) % MOD;
	} else {
		ans = (base + MOD - sum) % MOD;
	}
	cout << ans << endl;
	return 0;
}
