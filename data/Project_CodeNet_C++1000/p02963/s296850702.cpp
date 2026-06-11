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
    lint S;
    cin >> S;
    lint X1 = 0, Y1 = 0, X2 = 1e9, Y2 = 1, X3, Y3;
    // |X2*Y3-X3*Y2| == S を満たすX2,Y2,X3,Y3を求める．
    // X2==1e9,Y2 = 1とする
    // 1e9*Y3-X3*1 == S を満たすX2,Y2,X3,Y3を求める．
    if (S % (int)1e9 == 0) {
        Y3 = S / (int)1e9;
        X3 = 0;
    } else {
        Y3 = S / 1000000000 + 1;
        X3 = 1000000000 * Y3 - S;
    }

    cout << X1 << ' ' << Y1 << ' ' << X2 << ' ' << Y2 << ' ' << X3 << ' ' << Y3
         << endl;
    return 0;
}