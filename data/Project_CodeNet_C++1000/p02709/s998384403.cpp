#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ALL(x) (x).begin(),(x).end()
const int IINF = 1e9;
const LL LINF = 1e18;
const LL MOD = 1e9+7;

int main() {
    int N;
    cin >> N;
    vector<pair<LL, LL>> A(N + 1, pair<LL, LL>(LINF, 0));
    FOR(i, 1, N + 1) {
        LL a;
        cin >> a;
        A[i] = make_pair(a, i);
    }

    sort(ALL(A), greater<pair<LL, int>>());
    vector<vector<LL>> dp(N + 1, vector<LL>(N + 1, 0));

    FOR(i, 1, N + 1) {
        LL act = A[i].first;
        LL index = A[i].second;

        dp[i][0] = dp[i - 1][0] + abs(act*(index - i));
        dp[0][i] = dp[0][i - 1] + abs(act*(N - i + 1 - index));
    }

    FOR(i, 2, N + 1) {
        LL act = A[i].first;
        LL index = A[i].second;
        FOR(j, 1, i) {
            LL x = act*abs(index - (i - j));
            LL y = act*abs(N - j + 1 - index);
            LL sl = dp[i - j - 1][j] + x;
            LL sr = dp[i - j][j - 1] + y;
            dp[i - j][j] = max(sl, sr);
        }
    }

    LL res = 0;
    REP(i, N + 1) {
        res = max(res, dp[i][N - i]);
    }
    cout << res << endl;
    return 0;
}
