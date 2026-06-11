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
    int H, W, A, B;
    cin >> H >> W >> A >> B;

    vector<vector<int>> G(H, vector<int>(W, -1));
    // ddump(G);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i < B) {
                if (j < A) {
                    G[i][j] = 0;
                } else {
                    G[i][j] = 1;
                }
            } else {
                if (j < A) {
                    G[i][j] = 1;
                } else {
                    G[i][j] = 0;
                }
            }
        }
    }

    rep(i, H) {
        rep(j, W) { cout << G[i][j]; }
        cout << endl;
    }
    // ddump(G);
    return 0;
}
