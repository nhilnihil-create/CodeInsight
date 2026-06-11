#include <bits/stdc++.h>
using namespace std;

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int32 INF = 1e9;
const int32 MOD = 1e9+7;
const int64 LLINF = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define POSSIBLE cout << ((n) ? "POSSIBLE\n" : "IMPOSSIBLE\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define ALL(obj) (obj).begin(),(obj).end()
#define pii pair<int32,int32>
#define pll pair<int64,int64>
#define pb(a) push_back(a)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int32 n = s.size();
    vector<vector<int32>> dp(n+1,vector<int32>(2,INF));

    reverse(ALL(s));
    dp[0][0] = 0;
    REP(i,n){
        dp[i+1][0] = min(dp[i][0] + s[i] - '0', dp[i][1] + s[i] - '0' + 1);
        dp[i+1][1] = min(dp[i][0] + 10 - (s[i] - '0'), dp[i][1] + 10 - (s[i] - '0') - 1);
    }
    // REP(i,n+1){
    //     REP(j,2){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    ANS(min(dp[n][0], dp[n][1]+1));

    // dp[0][1] = 1;
    // FOR(i,1,n){
    //     dp[i+1][0] = min(dp[i][0] + s[i] - '0', dp[i][1] + 10 - (s[i] - '0'));
    //     dp[i+1][1] = min(dp[i][0] + s[i] - '0' + 1, dp[i][1] + 10 - (s[i] - '0'));
    // }
    // ANS(dp[n][0]);
    return 0;
}