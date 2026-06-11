#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
const long long MOD = 1000000007;

ll dp[1000010][2];

signed main(){
    string N;
    cin >> N;
    dp[0][1] = 1;
    REP(i, N.length()){
        dp[i + 1][0] = min(dp[i][0] + N[i] - '0', dp[i][1] + 10 - (N[i] - '0'));
        dp[i + 1][1] = min(dp[i][0] + N[i] - '0' + 1, dp[i][1] + 10 - (N[i] - '0') - 1);
    }
    PRINT(dp[N.length()][0]);
    return 0;
}