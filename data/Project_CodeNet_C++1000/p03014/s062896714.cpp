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
    int H, W;
    cin >> H >> W;
    vector<string> G(H);
    rep(i, H) cin >> G[i];

    vector<vector<lint>> L(H, vector<lint>(W, 0));
    vector<vector<lint>> R(H, vector<lint>(W, 0));
    vector<vector<lint>> U(H, vector<lint>(W, 0));
    vector<vector<lint>> D(H, vector<lint>(W, 0));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W - 1; j++) {
            L[i][j + 1] = L[i][j] + 1;
            if (G[i][j] == '#') L[i][j + 1] = 0;
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = W - 1; 0 < j; j--) {
            R[i][j - 1] = R[i][j] + 1;
            if (G[i][j] == '#') R[i][j - 1] = 0;
        }
    }
    for (int j = 0; j < W; j++) {
        for (int i = 0; i < H - 1; i++) {
            U[i + 1][j] = U[i][j] + 1;
            if (G[i][j] == '#') U[i + 1][j] = 0;
        }
    }
    for (int j = 0; j < W; j++) {
        for (int i = H - 1; 0 < i; i--) {
            D[i - 1][j] = D[i][j] + 1;
            if (G[i][j] == '#') D[i - 1][j] = 0;
        }
    }

    lint ans = -1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (G[i][j] == '#') continue;
            lint cnt = L[i][j] + R[i][j] + U[i][j] + D[i][j] + 1;
            ans      = max(ans, cnt);
        }
    }
    cout << ans << endl;

    return 0;
}