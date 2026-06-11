#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (ll (i) = 0 ; (i) < (ll)(n) ; ++(i))
#define REPN(i, m, n) for (ll (i) = m ; (i) < (ll)(n) ; ++(i))
#define REP_REV(i, n) for (ll (i) = (ll)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (ll (i) = (ll)(n) - 1 ; (i) >= m ; --(i))

#define INF             2e9
#define INF_LL          1LL<<60
#define ll              long long
#define Ceil(x, n)      (((((x))+((n)-1))/n))
#define CeilN(x, n)     (((((x))+((n)-1))/n)*n)
#define FloorN(x, n)    ((x)-(x)%(n))
#define ALL(x)          (x).begin(),(x).end()
typedef pair<ll, ll>    P;

int main() {
    int n;
    cin >> n;
    vector<P> a(n);
    REP(i, n) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(ALL(a));
    reverse(ALL(a));

    /* 活発度の高い順に左端 or 右端に詰めていく */
    /* 左端に詰める場合と右端に詰める場合とは動的計画法で試していく */
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));    /* dp[i][j]: 左にi人、右にj人詰めたときのうれしさの最大スコア */

    REP(i, n) REPN(j, 0, n-i) {
        /* 左につめる */
        dp[i+1][j] = max(dp[i+1][j], dp[i][j] + a[i+j].first * abs(a[i+j].second - i));

        /* 右につめる */ 
        dp[i][j+1] = max(dp[i][j+1], dp[i][j] + a[i+j].first * abs(a[i+j].second - (n - 1 - j)));
    }

    ll ans = 0;
    REP(i, n+1) {
        ans = max(ans, dp[i][n-i]);
    }

    cout << ans << endl;
}