#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> S(n),T(m);
    rep(i,n) cin >> S[i];
    rep(i,m) cin >> T[i];

    vector<vector<ll>> dp(n+1,vector<ll>(m+1,1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = (dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + (S[i-1]==T[j-1]?(dp[i-1][j-1]):0) + MOD)%MOD;
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}