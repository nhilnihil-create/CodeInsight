#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef array<int, 3> tri;
typedef array<int, 2> duo;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}


const int MOD = 1E9 + 7, N = 2001;
ll fact[N];
ll exp(int a, int n) {
        if (n == 0) return 1;
        ll b = exp(a, n / 2);
        (b *= b) %= MOD;
        if (n & 1) (b *= a) %= MOD;
        return b;
}

ll C(int n, int k) {
        if (k > n) return 0;
        return fact[n] * exp(fact[k], MOD - 2) % MOD * exp(fact[n - k], MOD - 2) % MOD;
}


void _main() {
        fact[0] = 1;
        int blue, n; cin >> n >> blue;
        int red = n - blue;
        for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
        for (int i = 1; i <= blue; i++) {
                cout << C(red + 1, i) *  C(blue - 1, i - 1) % MOD << '\n';
        }

}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}
