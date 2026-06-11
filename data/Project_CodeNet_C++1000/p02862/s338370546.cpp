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
    ll X, Y;
    cin >> X >> Y;

    if ((X + Y) % 3 != 0) {
        put(0);
        return;
    }

    ll step = (X + Y) / 3;
    ll nx = X - step;
    ll ny = Y - step;
    // nx+ny C nx 
    if (nx < 0 || ny < 0) {
        put(0);
        return;
    }

    ll mod = 7LL + 1e9;
    ll res = combination(nx + ny, nx, mod);
    put(res);
}
signed main(){ Main();return 0;}