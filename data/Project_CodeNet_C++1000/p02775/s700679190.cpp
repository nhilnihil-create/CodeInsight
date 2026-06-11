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
    cin >> S;
    reverse(ALL(S));
    vvi dp(S.size() + 1, vi(2, INF));
    dp[0][0] = 0;
    dp[0][1] = 1;
    REP(i, S.size()) {
        int s = S[i] - '0';
        REP(n, 10) {
            if (n < s) {
                dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + (n + 10) - s + n);
                dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + (n + 10 - 1) - s + n);
            } else if (n > s) {
                dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + n - s + n);
                dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + n - 1 - s + n);
            } else if (n == s) {
                dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + n - s + n);
                dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + (n + 10 - 1) - s + n);
            }
        }
    }
    cout << min(dp[S.size()][0], dp[S.size()][1] + 1) << endl;
}