#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define sz(s) (int)s.size()

const int MOD = 998244353;

int fpow(int x, int y) {
    int t = 1;
    for (; y > 0; y >>= 1) {
        if (y & 1) t = (1LL * t * x) % MOD;
        x = (1LL * x * x) % MOD;
    }
    return t;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> f;
    for (auto &v : a) {cin >> v; ++f[v];}
    if (a[0] != 0 || f[0] > 1) {cout << 0 << '\n'; return 0;}
    int mx = 0;
    for (auto p : f) mx = max(mx, p.first);
    if (mx == 0) {cout << "1\n"; return 0;}
    long long ans = 1LL;
    for (int i = mx; i > 0; --i) {
        // if (f[i - 1] == 0) {cout << "0\n"; return 0;}
        (ans *= fpow(f[i - 1], f[i])) %= MOD;
    }
    cout << ans << '\n';
    return 0;
}