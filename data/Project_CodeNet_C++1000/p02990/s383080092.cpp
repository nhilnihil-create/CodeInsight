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

// nCa
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
    ll n, K;
    cin >> n >> K;

    ll mod = 7LL + 1e9;
    repi (i, K + 1) {
        ll res = combination(K - 1, i - 1, mod) * combination(n - K + 1, i, mod);
        res %= mod;
        put(res);
    }
}
signed main(){ Main();return 0;}