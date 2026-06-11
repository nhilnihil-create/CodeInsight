#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define dump(a) cerr << #a << " = " << (a) << "(L:" << __LINE__ << ")" << endl

long long INF = 1LL << 60;
int N, M, X;
vector<long long> C;
vector<vector<int> > A;

int main() {
    cin >> N >> M >> X;
    C.resize(N);
    A.resize(N);
    rep (i, N) {
        cin >> C[i];
        A[i].resize(M);
        rep (j, M) {
            cin >> A[i][j];
        }
    }

    long long ans = INF;
    for (int b = 0; b < (1 << N); b++) {
        long long cost = 0;
        vector<int> params(M);
        for (int k = 0; k < N; k++) {
            if ((b >> k) & 1) {
                cost += C[k];
                rep (i, M) params[i] += A[k][i];
            }
        }
        bool ok = true;
        rep (i, M) if (params[i] < X) ok = false;
        if (ok) ans = min(ans, cost);
    }
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}
