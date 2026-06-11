#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MN = 1e6 + 5, MOD = 1e9 + 7;
ll f[MN], inv[MN];

ll fp(ll x, ll y, ll m = MOD) {
    ll r = 1;
    for (x %= m; y; y >>= 1, x = (x * x) % m) 
        if (y & 1) r = (r * x) % m;
    return r;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    f[0] = 1;
    for (int i = 1; i <= 1e6; i++) f[i] = (f[i - 1] * i) % MOD;
    inv[(int) 1e6] = fp(f[(int) 1e6], MOD - 2);
    for (int i = 1e6 - 1; i >= 0; i--) inv[i] = (inv[i + 1] * (i + 1)) % MOD;
    int X, Y; cin >> X >> Y;
    ll ans = 0;
    for (int i = 0; i <= X / 2; i++) {
        int j = X - i * 2;
        if (i + j * 2 == Y) {
            ans = (ans + (f[i + j] * inv[i] % MOD * inv[j] % MOD)) % MOD;
        }
    }
    cout << ans << '\n';
    return 0;
}