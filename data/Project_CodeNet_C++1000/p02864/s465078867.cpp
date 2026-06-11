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
#define mp make_pair

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int64 n,k;
    cin >> n >> k;
    vector<int64> h(n+1,0);
    REP(i,n)cin >> h[i+1];
    int64 ans = LLINF;
    vector<vector<int64>> dp(n+1,vector<int64>(n-k+1,LLINF));
    dp[0][0] = 0;
    FOR(i,1,n+1){
        FOR(j,1,n-k+1){
            REP(l,i)
                dp[i][j] = min(dp[i][j], dp[l][j-1] + max<int64>(0,h[i] - h[l]));
        }
    }
    FOR(i,0,n+1){
        ans = min(ans, dp[i][n-k]);
    }
    ANS(ans);
    return 0;
}