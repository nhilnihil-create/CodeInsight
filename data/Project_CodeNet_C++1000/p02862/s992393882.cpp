#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll md = 1000000007;
#define rep(i, b) for(i = 0; i < b; i++)
#define fr first
#define sc second
using vl = vector<ll>;
using vvl = vector<vl>;
vl fac(2,1), ifac(2,1);

ll ad(ll a, ll b, ll mod = md) {
    return (a%mod + b%mod + mod) % mod;
}

ll ml(ll a, ll b, ll mod = md) {
    return ( (a%mod) * (b%mod) ) % mod;
}

ll pw(ll x, ll n, ll mod = md) {
    ll res = 1;
    x %= mod;
    while (n) {
        if (n & 1)  res = (res*x)%mod;
        n = (n >> 1);
        x = (x*x)%mod;
    }
    return res;
}

void cachefact(ll lim, ll mod = md) {
    for(int i = 2; i <= lim; i++) {
        ifac.push_back((ifac[mod%i] * (mod - mod/i) % mod)%mod);
    }
    for(ll i = 2; i <= lim; i++) {
        fac.push_back((fac[i-1] * i)%mod);
        ifac[i] = (ifac[i-1] * ifac[i])%mod;
    }
}

ll C(int n, int r) {
    if(n < r || r < 0) return 0;
    return ml(fac[n], ml(ifac[r], ifac[n-r]));
}

ll PIE(ll n, ll k, ll e, ll s, ll mod = md) {
	if(e < 0 || k < 0 || n < 0) return 0;
	ll ans = 0;
	for(int i = 0; i <= n && (e+1) * i + (n-i)*s <= k; i++) {
		ans = ad(ans, (i&1 ? -1 : 1) * ml(C(n, i), C(n - 1 + k - (e+1) * i - (n - i) * s, n-1)));
	}
	return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie();
    cachefact(1000000);
    int x, y;
    cin >> x >> y;
    if((x + y)%3 == 0) {
    	int n = (x + y)/3;
	    cout << PIE(n, x, 2, 1) << "\n";
	} else {
		cout << "0\n";
	}
    return 0;
}