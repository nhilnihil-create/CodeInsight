#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
//using P = pair<int, int>;

const int mod = 1000000007;

ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

ll choose(ll n, ll r) {
    ll ret = 1;
    for (ll i = n; i > n-r;--i){
        ret *= i;
        ret %= mod;
    }
    for (ll i = 1; i < r+1; ++i) {
        // ret /= i;
        ret %= mod;
        ret = ret * modinv(i,mod) % mod;
    }
    return ret;
}

int main() {
    ll x, y;
    cin >> x >> y;
    if ((x+y)%3 != 0) {
        cout << 0 << endl;
        return 0;
    }
    ll n, m; // n:(+1,+2), m:(+2,+1)の回数
    n = (2*y-x)/3; m = (2*x-y)/3;
    if (n<0 || m<0) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = choose(ll(n+m),ll(n));
    cout << ans << endl;

    return 0;
}