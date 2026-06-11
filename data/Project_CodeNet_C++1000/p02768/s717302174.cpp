#include <bits/stdc++.h>
// #include <atcoder/all>
#define ll long long int
#define ld long double
#define yorn(f) cout<<((f)?"Yes":"No")<<endl;
#define YORN(f) cout<<((f)?"YES":"NO")<<endl;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i, n) for (ll i = 1; i < (ll)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
// using namespace atcoder;

ll mpow(ll x, ll n, ll mod){
    ll ans = 1;
    while(n != 0){
        if(n&1) ans = ans*x % mod;
        x = x*x % mod;
        n = n >> 1;
    }
    return ans;
}

ll combination(ll n, ll a, ll mod) {
    ll X = 1;
    for (ll i = n - a + 1; i <= n; i++) {
        X = (X * i) % mod;
    }
    ll Y = 1;
    for (ll i = 1; i <= a; i++) {
        Y = (Y * i) % mod;
    }

    ll iY = mpow(Y, mod - 2, mod);
    return X * iY % mod;
}

void Main()
{
    ll n, a, b;
    cin >> n >> a >> b;

    ll mod = 1e9 + 7LL;
    ll res = mpow(2, n, mod);
    res = (res - 1 + mod) % mod;
    res = (res - combination(n, a, mod) + mod) % mod;
    res = (res - combination(n, b, mod) + mod) % mod;

    put(res);
}
signed main(){ Main();return 0;}