#include <bits/stdc++.h>
using namespace std;

#define d(x) cerr << #x ":" << x << endl;
#define dd(x, y) cerr << "(" #x "," #y "):(" << x << "," << y << ")" << endl
#define rep(i, n) for (int i = (int)(0); i < (int)(n); i++)
#define repp(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define all(v) v.begin(), v.end()
#define dump(v)                  \
    cerr << #v ":[ ";            \
    for (auto macro_vi : v) {    \
        cerr << macro_vi << " "; \
    }                            \
    cerr << "]" << endl;
#define ddump(v)                           \
    cerr << #v ":" << endl;                \
    for (auto macro_row : v) {             \
        cerr << "[";                       \
        for (auto macro__vi : macro_row) { \
            cerr << macro__vi << " ";      \
        }                                  \
        cerr << "]" << endl;               \
    }
using lint       = long long;
const int INF    = 1e9;
const lint LINF  = 1e18;
const lint MOD   = 1e9 + 7;
const double EPS = 1e-10;

int main() {
    lint N;
    cin >> N;
    vector<lint> A(N, 0);
    rep(i, N) cin >> A[i];

    lint ans = 0;
    lint f   = 1;
    for (int d = 0; d <= 61; d++) {
        lint cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] & (1ll << d))
                cnt1++;
            else
                cnt0++;
        }
        lint add = (cnt0 * cnt1) % MOD * f % MOD;
        ans      = (ans + add) % MOD;
        f        = (f * 2ll) % MOD;
    }
    cout << ans << endl;
    return 0;
}