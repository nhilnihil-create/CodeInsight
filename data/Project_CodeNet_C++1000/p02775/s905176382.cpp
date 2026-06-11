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
#define print(x)        cout << (x) << endl
#define printa(x)       REP(i, x.size()) cout << x[i] << endl
typedef pair<ll, ll>    P;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    vector<int> a(n+1);
    REPN(i, 1, n+1) a[i] = s[i-1] - '0';

    int dp[n+1][2];    /* 0: ぴったり, 1: 多い */
    dp[0][1] = a[0] + 1;
    dp[0][0] = a[0];

    REP(i, n) {
        /* ぴったり払って終わる */
        dp[i+1][0] = dp[i][0] + a[i+1];
        /* おつりもらって終わる */
        dp[i+1][0] = min(dp[i+1][0], dp[i][1] + 10 - a[i+1]);

        /* 一枚多く支払って終わる */
        dp[i+1][1] = dp[i][0] + a[i+1] + 1;

        /* おつりをもらって終わる */
        /* 下の桁を考慮し9から引く */
        dp[i+1][1] = min(dp[i+1][1], dp[i][1] + 9 - a[i+1]);
    }

    cout << dp[n][0] << endl;

    return 0;
}