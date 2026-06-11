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
vl p, B, fac(2, 1), ifac(2, 1);

ll ad(ll a, ll b, ll mod = md) {
    return (a%mod + b%mod + mod) % mod;
}

ll ml(ll a, ll b, ll mod = md) {
    return ( (a%mod) * (b%mod) ) % mod;
}

ll fn(ll a, ll r, ll n, ll mod = md) {
    ll res = 1, ans = 0;
    r %= mod;
    if(r < 0) r+=mod;
    while(n) {
        if(n&1) ans = (r*ans + res)%mod;
        res = (res*r + res)%mod;
        r = (r*r)%mod;
        n = n/2;
    }
    ans = (ans*a)%mod;
    if(ans < 0) ans += md;
    return ans;
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

ll P(int n, int r) {
    if(n < r) return 0;
    return ml(fac[n], ifac[n-r]);
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
        if(prime[i]) p.push_back(i);
    }
}

ll Phi(ll n) {
    ll res = n;
    for (int i = 0; p[i] * p[i] <= n; i++) {
        short cnt = 0;
        while (n % p[i] == 0) {
               n /= p[i];
               cnt++;
        }
        if(cnt) res -= (res / p[i]);
    }
    if (n > 1) res -= (res / n);
    return res;
}

void sieveGCD(ll lim, vector<ll> &tab) {
    int pn = p.size();
    for(int  i = 1; i <= lim; i++) tab[i] = i;
    for(int i = 0; i < pn && p[i] <= lim; i++) {
        for(int j = p[i]; j <= lim; j += p[i]) {
            tab[j] = (tab[j]/p[i])*(p[i]-1);
        }
    }
}

void sieveMU(ll n, vl &mu) {
    vl factor(n+1, 0);
    for(int i = 2; i * i <= n; i++) {
        if(!factor[i]) {
            for(int j = i * i; j <= n; j += i) factor[j] = i;
        }
    }
    mu[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(!factor[i]) {
            mu[i] = -1;
            continue;
        }
        if((i/factor[i])%factor[i] == 0) {
            mu[i] = 0;
        } else {
            mu[i] = (-1)*mu[i/factor[i]];
        }
    }
}

ll extended_euclid(ll a, ll b, ll *x, ll *y) { 
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    ll x1, y1;
    ll gcd = extended_euclid(b%a, a, &x1, &y1);  
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;  
}

ll crt(vector<pair<ll,ll>> &a, int an, ll m) {
    ll ret = 0;
    for(int i = 0; i < an; i++) {
        ll p = m / a[i].second, q = a[i].second, r, s;
        int g = extended_euclid(p, q, &r, &s);
        ret = ad(ret, ml(a[i].first, ml(r, p, m), m), m);
    }
    return ret;
}

void multiply(vvl &F, vvl &R, ll N) {
	vvl temp(N, vl (N, 0));
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			for(int k = 0; k < N; k++) {
				temp[i][j] = ad(temp[i][j], ml(F[i][k], R[k][j]));
			}
		}
	}
	F = temp;
}

void mpow(vvl &F, ll N, ll n) {
	vvl res(N, vl (N, 0));
	for(int i = 0; i < N; i++) res[i][i] = 1;
	while(n) {
		if(n&1) multiply(res, F, N);
		multiply(F, F, N);
		n >>= 1;
	}
	F = res;
}

const int N = 4e5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vl mu(N+1), dp(N+1), pwr(N+1);
    sieveMU(N, mu);
   	ll n=0, k;
   	string nn;
   	cin >> nn >> k;
   	int sn=nn.size();
   	for(int i=0; i<sn;++i)
   		n = (n * 10 + nn[i] - '0') % (md - 1);

   	for(int i = 1; i <= N; ++i) {
   		pwr[i] = pw(i, n);
   	}

   	for(int i = 1; i <= N; ++i) {
   		for(int j = i; j <= N; j += i) {
   			dp[j] += mu[i] * (pwr[j/i] - pwr[j/i - 1]);
   			if(dp[j] > md) dp[j] -= md;
   			if(dp[j] < 0) dp[j] += md;
   		}
   	}

   	for(int i = 1; i <= N; ++i) {
   		dp[i] += dp[i-1];
   		dp[i] %= md;
   	}
   	map<ll,ll> m;
   	ll cur, curr;
   	// auto start = chrono::steady_clock::now();
   	for(ll i = N+1; i <= k; i = cur + 1) {
   		cur = k/(k/i);
   		ll &c = m[cur];
   		c = pw(cur, n);
   		ll x;
   		for(ll j = 2; j <+ cur; j = curr + 1) {
   			x = cur/j;
   			curr = cur/x;
   			c -= (curr - j + 1) * (x <= N ? dp[x] : m[x]);
   		}
   	}
	ll ans = 0;
   	for(ll i = 1; i <= k; i = cur + 1) {
   		cur = k/(k/i);
   		ans += (((cur - i + 1) * (i + cur))/2) * (k/cur <= N ? dp[k/cur] : m[k/cur]);
   		ans %= md;
   	}
   	cout << ans << "\n";

   	// auto end = chrono::steady_clock::now();
   	// auto diff = end - start;
   	// cout << chrono::duration<double, milli> (diff).count() << "\n";
    return 0;
}