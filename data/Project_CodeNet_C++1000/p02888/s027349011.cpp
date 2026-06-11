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
    int N;
    cin >> N;
    vector<lint> L(N);
    rep(i, N) cin >> L[i];
    sort(L.begin(), L.end());
    dump(L);

    lint cnt = 0;
    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            lint a = L[i], b = L[j];
            lint S = a + b;
            // a <= b
            // a+b>c ng? c<a+b
            // a+c>b ok
            // b+c>a ok
            // [j+1,N)の範囲で S=a+b < L[k] を満たす k の個数を求める

            int idx = lower_bound(L.begin(), L.end(), S) - L.begin();
            // dd(i, j);
            // dd(S, idx);
            cnt += max(0, idx - (j + 1));
        }
    }
    cout << cnt << endl;
    return 0;
}