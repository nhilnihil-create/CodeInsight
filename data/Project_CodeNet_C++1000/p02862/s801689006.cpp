#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef array<int, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}


const int MOD = 1E9 + 7, N = 1E6 + 1;
ll fact[N];
ll exp(int a, int n) {
        if (n == 0) return 1;
        ll b = exp(a, n / 2);
        (b *= b) %= MOD;
        if (n & 1) (b *= a) %= MOD;
        return b;
}

ll C(int n, int k) {
        return fact[n] * exp(fact[k], MOD - 2) % MOD * exp(fact[n - k], MOD - 2) % MOD;
}

void _main() {
        ll x, y; cin >> x >> y;
        if ((2 * x - y) % 3 || 2 * x - y < 0) {
                cout << 0;
                return;
        }

        int a = (2 * x  - y) / 3;
        int b = a - x + y;
        if (a < 0 || b < 0) {
                cout << 0;
                return;
        }

        fact[0] = 1;
        for (int i = 1; i <= a + b; i++) fact[i] = fact[i - 1] * i % MOD;

        cout << C(a + b, a);
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}