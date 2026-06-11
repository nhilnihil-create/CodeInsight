#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef array<int, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}


const int MOD = 1E9 + 7;
ll exp(int a, int n) {
        if (n == 0) return 1;
        ll b = exp(a, n / 2);
        (b *= b) %= MOD;
        if (n & 1) (b *= a) %= MOD;
        return b;
}


int choose(int n, int k) {
        ll x = 1, y = 1;
        for (int i = n; i >= n - k + 1; i--) (x *= i) %= MOD;
        for (int i = 1; i <= k; i++) (y *= i) %= MOD;
        return x * exp(y, MOD - 2) % MOD;
}


void _main() {
        int n, a, b; cin >> n >> a >> b;
        cout << (exp(2, n) - 1 - choose(n, a) - choose(n, b) + MOD + MOD + MOD) % MOD;
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}
