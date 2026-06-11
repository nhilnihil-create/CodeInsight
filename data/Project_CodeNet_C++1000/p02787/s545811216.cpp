#include <bits/stdc++.h>
using namespace std;

#define d(x) cerr << #x ":" << x << endl;
#define dd(x, y) cerr << "(" #x "," #y "):(" << x << "," << y << ")" << endl
#define rep(i, n) for (int i = (int)(0); i < (int)(n); i++)
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
const double EPS = 1e-10;

int main() {
    lint H, N;
    cin >> H >> N;
    vector<lint> a(N), b(N);
    rep(i, N) cin >> a[i] >> b[i];
    vector<lint> mi(H + 1, LINF);
    mi[0] = 0;
    for (int h = 0; h <= H; h++) {
        if (mi[h] == LINF) continue;
        for (int i = 0; i < N; i++) {
            lint to = min(h + a[i], H);
            mi[to]  = min(mi[to], mi[h] + b[i]);
        }
    }
    cout << mi[H] << endl;

    return 0;
}