#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll md = 1000000007;
typedef vector<vector<ll>> vvl;
typedef vector<ll> vl;
vl p, fac(2, 1), ifac(2, 1);

ll add(ll a, ll b, ll mod = md) {
    return (a%mod + b%mod + mod) % mod;
}

ll mul(ll a, ll b, ll mod = md) {
    return ( (a%mod) * (b%mod) ) % mod;
}

ll power(ll x, ll n, ll mod = md) {
    ll res = 1;
    x %= mod;
    while (n) {
        if (n & 1)  res = ((res%mod) * (x%mod))%mod;
        n = (n >> 1);
        x = ((x%mod) * (x%mod))%mod;
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

ll C(ll n, ll r, ll mod = md) {
    if(n < r) return 0;
    return mul(fac[n], mul(ifac[r], ifac[n-r], mod), mod);
}

void sieve(ll n) {
	vector<bool> prime(n+1, true);
    for(int i = 2; i*i <= n; i++) {
        if(prime[i]) {
            for(int j = i*i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
    p.push_back(2);
    for(int i = 3; i <= n; i += 2) {
        if(prime[i]) {
            p.push_back(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   	ll n, m;
   	cin >> n >> m;
   	vl dp(n+1, 0), a(m, 0);
   	for(int i = 0; i < m; i++) {
   		cin >> a[i];
   	}
   	int cur = 0;
   	sort(a.begin(), a.end());
   	dp[0] = 1;
   	for(int i = 1; i <= n; i++) {
   		if(cur < m && i == a[cur]) {
   			cur++;
   		} else {
   			dp[i] = (dp[i-1] + (i-2 >= 0 ? dp[i-2] : 0))%md;
   		}
   	}
   	cout << dp[n] << "\n";
    return 0;
}
