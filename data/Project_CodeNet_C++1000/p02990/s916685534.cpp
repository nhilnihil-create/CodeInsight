#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repr(i, n) for(ll i = n; i >= 0; i--)
#define reprr(i, m, n) for (ll i = m; i < n; i++)
#define inf 2e9
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

ll modinv(ll a, ll m) {
    ll x = a, y = m, u = 1, v = 0;
    while (y) {
        ll div = x / y;
        x -= div * y; swap(x, y);
        u -= div * v; swap(u, v);
    }
    return (u % m + m) % m;
}

ll comb(ll n, ll k, ll mod) {
    ll dividend = 1, divisor = 1;
    rep(i, k) {
        dividend = dividend * (n - i) % mod;
        divisor = divisor * modinv(i + 1, mod) % mod;
    }
    return (dividend * divisor) % mod;
}



int main()
{
    ll N, K; cin >> N >> K;
    ll mod = 1e9+7;
    reprr(i, 1, K + 1) {
        cout << comb(N - K + 1, i, mod) * comb(K - 1, i - 1, mod) % mod << endl;
    }
    return 0;
}