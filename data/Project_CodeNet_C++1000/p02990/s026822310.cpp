#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

int n, k;
const int N = 2010;
const int mod = 1e9 + 7;
ll fac[N], inv[N];

ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void init() {
    fac[0] = 1;
    for (int i = 1; i < N; ++i) {
        fac[i] = fac[i - 1] * i % mod;
    }
    inv[N - 1] = power(fac[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; --i) {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
}

ll C(ll a, ll b) {
    return fac[a] * inv[b] % mod * inv[a - b] % mod;
}

int main() {
    init();
    cin >> n >> k;
    int r = n - k;
    for (int i = 1; i <= k; ++i) {
        if (i > r + 1) { // put i into r + 1 slots
            cout << 0 << endl;
        } else {
            int res = C(r + 1, i) * C(k - 1, i - 1) % mod;
            cout << res << endl;
        }
    }
    return 0;
}
