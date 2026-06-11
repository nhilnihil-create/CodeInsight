#include <bits/stdc++.h>


using namespace std;


#ifdef zxc

#include "debug.h"

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

using ll = int64_t;
using ld = long double;
const ld EPS = 1e-8;
const ll MOD = 998244353;
const ld PI = 3.141592653589793;
const int maxn = 1000001;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int a[maxn];

signed main() {
#ifdef zxc
    mt19937 mt(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    freopen("../kolya_input.txt", "r", stdin);
//    freopen("../kolya_output.txt", "w", stdout);
#else
    mt19937 mt(228);
//            freopen("", "r", stdin);
//        freopen("hack.out", "w", stdout);
#endif
    fast_io();
    cout.precision(10);
    cout << fixed;
    auto start = chrono::steady_clock::now();
///

    int n;
    cin >> n;
    string s;
    cin >> s;
    while (s.size()) {
        a[s.size()] = s.back();
        s.pop_back();
    }
    for (int i = 1; i < n; ++i) {
        a[i - 1] = abs(a[i] - a[i + 1]);
    }
    --n;
    int parity = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] & 1 && ((n - 1) & i) == i) {
            ++parity;
        }
    }
    if (parity & 1) {
        cout << 1;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] & 1) {
            cout << 0;
            return 0;
        }
    }
    parity = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 2 && ((n - 1) & i) == i) {
            ++parity;
        }
    }
    if (parity & 1) {
        cout << 2 << "\n";
    } else {
        cout << "0";
    }
///
    auto end = chrono::steady_clock::now();
    debug("time", chrono::duration_cast<chrono::milliseconds>(end - start).count() / 1000.0);
}

