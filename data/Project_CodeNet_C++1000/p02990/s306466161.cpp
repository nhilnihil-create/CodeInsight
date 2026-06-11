#include <bits/stdc++.h>

#define EPS (1e-10)
#define rep(i, a, b) for (int i = a; i < (int)(b); ++i)
#define rrep(i, a, b) for (int i = b - 1; i >= (int)(a); --i)
#define all(a) a.begin(), a.end()

using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvb = vector<vb>;

constexpr int MOD = 1000000007;

ll mod(ll x) {
    x %= MOD;
    if (x < 0) { x += MOD; }
    return x;
}

ll mpow(ll x, ll p) {
    if (p == 0) { return 1; }
    if (p % 2 == 1) { return mod(x * mpow(x, p - 1)); }
    ll sub = mpow(x, p / 2);
    return mod(sub * sub);
}

ll mcombination(const vll& fac, const vll& inv, ll n, ll r) {
    if (r == 0 || r == n) { return 1; }
    return mod(mod(fac[n] * inv[n - r]) * inv[r]);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;

    vll fac(n + 1), inv(n + 1);

    fac[0] = 1;
    rep(i, 1, n + 1) { fac[i] = mod(i * fac[i - 1]); }

    inv[n] = mpow(fac[n], MOD - 2);
    rrep(i, 0, n) { inv[i] = mod((i + 1) * inv[i + 1]); }

    ll r = n - k;
    rep(i, 1, k + 1) {
        if (r + 1 < i) {
            cout << 0 << endl;
            continue;
        }
        ll t1 = mcombination(fac, inv, r + 1, i);
        ll t2 = mcombination(fac, inv, k - 1, i - 1);
        cout << mod(t1 * t2) << endl;
    }

    return 0;
}