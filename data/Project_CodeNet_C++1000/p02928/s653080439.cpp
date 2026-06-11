#include <bits/stdc++.h>

using namespace std;


#ifdef zxc

#include <sys/resource.h>
#include "debug.h"

#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

using ll = int64_t;
using ld = long double;
const ld EPS = 1e-9;
//const ll MOD = 924844033;
const ld PI = 3.141592653589793;
const int maxn = 300001;
const ll MOD = 1e9 + 7;

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

ll pw(ll a, ll b) {
    ll res = 1;
    for (; b; b >>= 1) {
        if (b & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
    }
    return res;
}

template<typename Cont>
vector<vector<int>> accum2d(Cont a, int n, int m) {
    vector<vector<int>> res(n, vector<int>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            res[i][j] = a[i][j];
            if (i > 0) {
                res[i][j] += res[i - 1][j];
            }
            if (j > 0) {
                res[i][j] += res[i][j - 1];
            }
            if (i > 0 && j > 0) {
                res[i][j] -= res[i - 1][j - 1];
            }
        }
    }
    return res;
}

vector<vector<int>> resize2d(vector<vector<int>> a, int n, int m) {
    a.resize(n);
    for (auto &x:a) {
        x.resize(m);
    }
    return a;
}

int up[1030][1030];
int down[1030][1030];
int lft[1030][1030];
int rght[1030][1030];
int ans[1030][1030];
int pref[1030][1030];
int arifm[1030][1030];
int dp1[1030][1030];
int dp2[1030][1030];

signed main() {
#ifdef zxc
    struct rlimit rl;
    const rlim_t kStackSize = 512L * 1024L * 1024L;
    assert(!getrlimit(RLIMIT_STACK, &rl));
    rl.rlim_cur = kStackSize;
    assert(!setrlimit(RLIMIT_STACK, &rl));
    freopen("../kolya_input.txt", "r", stdin);
//    freopen("../kolya_output.txt", "w", stdout);
#else
    //    mt19937 mt(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    //            freopen("", "r", stdin);
    //        freopen("hack.out", "w", stdout);
#endif
    auto solve = [](int _) {
        int n;
        cin >> n;
        ll k;
        cin >> k;
        vector<int> a(n);
        for (int &el:a) {
            cin >> el;
        }
        ll ans = 0;

        for (int i = 0; i < n; ++i) {
            int pref = 0;
            int val = 0;
            for (int j = 0; j < n; ++j) {
                if (a[i] < a[j]) {
                    ++val;
                    if (j < i) {
                        ++pref;
                    }
                }
            }
            ans += 1ll * k * (k - 1) / 2 % MOD * val % MOD + pref * k;
            ans %= MOD;
        }
        cout<<ans;
    };


    fast_io();
    cout.precision(9);
    cout << fixed;
    auto start = chrono::steady_clock::now();
    for (int i = 1; i <= 1; ++i)solve(i);
    auto end = chrono::steady_clock::now();

    debug("time", chrono::duration_cast<chrono::milliseconds>(end - start).count() / 1000.0);

}
