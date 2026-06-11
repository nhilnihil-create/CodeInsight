#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

typedef long long ll;

ll mod_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    ll k, q;
    cin >> k >> q;
    vector<ll> d(k);
    rep(i, k) cin >> d[i];
    rep(i, q) {
        ll n, x, m;
        cin >> n >> x >> m;
        vector<ll> s(k + 1, 0), e(k + 1, 0);
        rep(i, k) {
            s[i + 1] = s[i] + (d[i] % m);
            e[i + 1] = e[i];
            if (d[i] % m == 0) e[i + 1]++;
        }
        ll t = (x % m) + (n - 1) / k * s[k] + s[(n - 1) % k];
        cout << n - 1 - t / m - (n - 1) / k * e[k] - e[(n - 1) % k] << endl;
    }
}