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
#define vvvi vector<vector<vector<int>>>
#define pi pair<int, int>
#define ALL(a) (a).begin(), (a).end()
#define BIT(n) (1LL << (n))
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end()) //sortしてからつかうこと
constexpr ll MOD = 1e9 + 7;
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
ll A, B, C, D, E, F, G, H, N, M, L, K, P, Q, R, W, X, Y, Z;
string S;
ll T;
ll ans = 0;

template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
    for (T &x : vec)
        is >> x;
    return is;
}

signed main() {
    cin >> N >> T;
    vi a(N), b(N);
    REP(i, N) {
        cin >> a[i] >> b[i];
    }
    vvi dp(T, vi(2, -1));
    dp[0][0] = 0;
    REP(n, N) {
        auto tmp = dp;
        REP(t, T) {
            if (tmp[t][0] != -1) {
                dp[t][1] = max(dp[t][1], tmp[t][0] + b[n]);
                if (t + a[n] < T) {
                    dp[t + a[n]][0] = max(dp[t + a[n]][0], tmp[t][0] + b[n]);
                }
            }
            if (tmp[t][1] != -1) {
                if (t + a[n] < T) {
                    dp[t + a[n]][1] = max(dp[t + a[n]][1], tmp[t][1] + b[n]);
                }
            }
        }
        dump(dp);
    }
    REP(t, T) {
        ans = max((int)ans, dp[t][1]);
    }
    cout << ans << endl;
}