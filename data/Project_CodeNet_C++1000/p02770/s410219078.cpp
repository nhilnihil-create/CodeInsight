#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...) 0
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll k, q;
    cin >> k >> q;
    vector<ll> d(k);
    rep(i, 0, k) cin >> d[i];
    rep(t, 0, q) {
        ll n, x, m;
        cin >> n >> x >> m;
        x %= m;
        vector<ll> c = d;
        ll zcnt = 0, sum = 0;
        rep(i, 0, k) {
            c[i] %= m;
            sum += c[i];
            if (c[i] == 0) zcnt++;
        }
        debug(c, sum, zcnt);
        sum *= (n - 1) / k;
        zcnt *= (n - 1) / k;
        rep(i, 0, n - 1 - (n - 1) / k * k) {
            sum += c[i];
            if (c[i] == 0) zcnt++;
        }
        debug(sum, zcnt);
        sum = (sum + x) / m - x / m;
        cout << n - 1 - sum - zcnt << endl;
    }
}