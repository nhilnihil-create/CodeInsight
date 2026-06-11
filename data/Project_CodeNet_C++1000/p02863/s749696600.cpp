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
    int32 n,t;
    cin >> n >> t;
    vector<pii> ab(n);
    REP(i,n)cin >> ab[i].first >> ab[i].second;
    vector<vector<int32>> dp1(n+1,vector<int32>(t,0)), dp2(n+2,vector<int32>(t,0));
    REP(i,n){
        FORR(j,t-1,0){
            dp1[i+1][j] = dp1[i][j];
            if(j-ab[i].first < 0)continue;
            dp1[i+1][j] = max(dp1[i+1][j], dp1[i][j-ab[i].first] + ab[i].second);
        }
    }
    FORR(i,n-1,0){
        FORR(j,t-1,0){
            dp2[i+1][j] = dp2[i+2][j];
            if(j-ab[i].first < 0)continue;
            dp2[i+1][j] = max(dp2[i+1][j], dp2[i+2][j-ab[i].first] + ab[i].second);
        }
    }
    int32 ans = 0;
    FOR(i,1,n+1){
        REP(j,t){
            // cout << i << " " << j << " " << dp1[i-1][t-1-j] << " " << dp2[i+1][j] << " " << ab[i-1].second << " " << dp1[i-1][t-1-j] + dp2[i+1][j] + ab[i-1].second << endl;
            ans = max(ans, dp1[i-1][t-1-j] + dp2[i+1][j] + ab[i-1].second);
        }
    }
    ANS(ans);
    return 0;
}