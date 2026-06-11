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
    int32 n;
    cin >> n;
    vector<pii> a(n);
    REP(i,n){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.rbegin(),a.rend());
    vector<vector<int64>> dp(n+1,vector<int64>(n+1,-LLINF)); //i番目までのうちj-1個を左に振った
    dp[0][0] = 0;
    REP(i,n){
        REP(j,n){
            if(i + j >= n)continue;
            dp[i+1][j] = max(dp[i+1][j], dp[i][j] + a[i+j].first * abs(i - a[i+j].second));
            dp[i][j+1] = max(dp[i][j+1], dp[i][j] + a[i+j].first * abs(n-1-j - a[i+j].second));
        }
    }
    // REP(i,n+1){
    //     REP(j,n+1)cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    int64 ans = 0;
    REP(i,n+1)ans = max(ans, dp[i][n-i]);
    ANS(ans);
    return 0;
}