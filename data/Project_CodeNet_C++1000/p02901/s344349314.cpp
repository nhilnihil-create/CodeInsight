#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define dump(...)
#endif
#define endl "\n"
#define ll long long
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define REP(i, x) for (int i = 0; i < (int)(x); i++)
#define REPS(i, x) for (int i = 1; i <= (int)(x); i++)
#define RREP(i, x) for (int i = ((int)(x)-1); i >= 0; i--)
#define RREPS(i, x) for (int i = ((int)(x)); i > 0; i--)
#define INF 2147483647
#define LLINF 9223372036854775807LL
#define vi vector<int>
#define vvi vector<vector<int>>
#define pi pair<int, int>
#define ALL(a) (a).begin(), (a).end()
#define BIT(n) (1LL << (n))
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end()) //sortしてからつかうこと
constexpr ll MOD = 1e9 + 7;
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
ll A, B, C, D, E, F, G, H, N, M, L, K, P, Q, R, W, X, Y, Z;
string S, T;
ll ans = 0;

template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (T &x : vec)
        is >> x;
    return is;
}

signed main() {
    cin >> N >> M;
    vi c(M);
    vi a(M);
    int n = 1 << N;
    REP(i, M) {
        cin >> a[i] >> B;
        vi b(B);
        cin >> b;
        int tmp = 0;
        REP(i, B) {
            tmp |= (1 << (b[i] - 1));
        }
        c[i] = tmp;
    }
    dump(c);
    vvi dp(M + 1, vi(n, INF));
    dp[0][0] = 0;
    REP(i, M) {
        REP(j, n) {
            if (dp[i][j] == INF)
                continue;
            int nxtj = j | c[i];
            dp[i + 1][nxtj] = min(dp[i + 1][nxtj], dp[i][j] + a[i]);
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
        }
    }
    dump(dp[M]);
    if (dp[M][n - 1] == INF)
        cout << -1 << endl;
    else
        cout << dp[M][n - 1] << endl;
}