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

int N, M, Q;
vector<lint> a, b, c, d;

lint ma = -1;
void bfs(int i, vector<lint>& A) {
    if (i == 0) {
        for (int x = 1; x <= M; x++) {
            A[i] = x;
            bfs(i + 1, A);
        }
    } else if (i == N) {
        // dump(A);

        lint score = 0;
        for (int i = 0; i < Q; i++) {
            if (A[b[i]] - A[a[i]] == c[i]) score += d[i];
        }
        ma = max(ma, score);
    } else {
        for (int x = A[i - 1]; x <= M; x++) {
            A[i] = x;
            bfs(i + 1, A);
        }
    }
    return;
}

int main() {
    cin >> N >> M >> Q;
    a = b = c = d = vector<lint>(Q);
    rep(i, Q) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]--, b[i]--;
    }

    vector<lint> A(N);

    bfs(0, A);

    cout << ma << endl;

    return 0;
}