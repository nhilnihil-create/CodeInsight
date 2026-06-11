
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
int x, y;
ll fac[N], inv[N];

ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = (res * a) % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void init() {
    fac[0] = 1;
    for (int i = 1; i < N; ++i) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    inv[N - 1] = power(fac[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; --i) {
        inv[i] = inv[i + 1] * (i + 1) % MOD;
    }
}

ll C(ll a, ll b) {
    return fac[a] * inv[b] % MOD * inv[a - b] % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    cin >> x >> y;
    int sum = x + y;
    if (sum % 3) {
        cout << 0 << endl;
    } else {
        int cnt = sum / 3;
        int two = x - cnt;
        if (two < 0 || two > cnt) {
            cout << 0 << endl;
            exit(0);
        }
        ll res = C(cnt, two);
        cout << res << endl;
    }

    return 0;
}

