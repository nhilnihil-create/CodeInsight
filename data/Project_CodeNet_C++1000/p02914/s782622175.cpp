#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll s = 0;
    rep(i, n) s ^= a[i];
    ll ans = s;
    rep(i, n) a[i] &= ~s;

    // Gaussian Elimination under XOR operation (not under addition)
    int ranks = 0;
    vector<int> top(n);
    for (int i = 60; i >= 0; --i) {
        int j = ranks;
        for (; j < n; ++j) {
            if (a[j] >> i & 1) {
                swap(a[ranks], a[j]);
                break;
            }
        }
        if (j == n) continue;
        top[ranks] = i;
        rep(k, n) {
            if (ranks == k) continue;
            if (a[k] >> i & 1) a[k] ^= a[ranks];
        }
        ++ranks;
    }

    ll x = 0;
    for (int i = 60; i >= 0; --i) {
        ll nx = x | (1ll << i);
        ll b = nx;
        rep(j, ranks) {
            if (b >> top[j] & 1) b ^= a[j];
        }
        if ((b & nx) == 0) {
            x = nx;
        }
    }
    ans += x * 2;
    cout << ans << endl;
    return 0;
}
