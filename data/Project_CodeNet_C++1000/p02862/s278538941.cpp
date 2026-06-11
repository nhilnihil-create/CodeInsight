#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define PRINT(x) cout<<(x)<<endl
#define INF 1000000000000 // 10^12
#define MOD 1000000007 // 10^9+7
#define PB push_back
#define MP make_pair

const int MAX_NUM = 3000000;

ll X, Y;

ll modinv(ll a, ll mod) {
    ll b = mod, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= mod;
    if (u < 0) u += mod;
    return u;
}

vector<ll> mf(MAX_NUM, -1);
ll modfact(ll n, ll mod) {
    if (mf[n] != -1) return mf[n];
    if (n == 0) return mf[0] = 1;
    return mf[n] = (n * modfact(n-1, mod)) % mod;
}

vector<ll> mif(MAX_NUM, -1);
ll modinvfact(ll n, ll mod) {
    if (mif[n] != -1) return mif[n];
    if (n == 0) return mif[0] = 1;
    return mif[n] = (modinv(n, mod) * modinvfact(n-1, mod)) % mod;
}

ll modcomb(ll n, ll k, ll mod) {
    return ((modfact(n, mod) * modinvfact(k, mod)) % mod * modinvfact(n-k, mod)) % mod;
}

int main() {
    cin >> X >> Y;
    ll ans;
    if (2*Y - X >= 0 && 2*X - Y >= 0 && (2*X - Y) % 3 == 0) {
        ll a = (2*Y - X) / 3;
        ll b = (2*X - Y) / 3;
        ans = modcomb(a+b, a, MOD);
    }
    else {
        ans = 0;
    }
    PRINT(ans);
    return 0;
}