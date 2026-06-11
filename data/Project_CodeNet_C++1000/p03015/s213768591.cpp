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
    string L;
    cin >> L;
    int n = L.size();
    vector<vector<ll>> dp(n+1,vector<ll>(2,0));
    dp[0][0] = 1;
    for(int i=1;i<=n;i++){
        int ld = L[i-1] - '0';
        if(ld == 1){
            dp[i][0] = (2*dp[i-1][0])%MOD;
            dp[i][1] = (3*dp[i-1][1] + dp[i-1][0])%MOD;
        }else{
            dp[i][0] = dp[i-1][0];
            dp[i][1] = (3*dp[i-1][1])%MOD;
        }
    }
    cout << (dp[n][0] + dp[n][1])%MOD << endl;
    return 0;
}