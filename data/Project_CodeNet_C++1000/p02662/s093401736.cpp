#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P  = pair<int,int>;
using v  = vector<ll>;
using vv = vector<v>;
//const int MOD = 1000000007;
const int MOD = 998244353;
const ll INF = 1001001001001;

int main(){
    ll n,s;cin>>n>>s;
    
    vv dp(n+1, v (s+2, 0));
    dp[0][0] = 1;
    
    ll a;
    
    rep(i,n){
        cin>>a;
        
        for(int j=s; j>=0; j--){
            dp[i+1][j] = 2 * dp[i][j];
            dp[i+1][j] %= MOD;
        }
        
        for(int j=s-a; j>=0; j--){
            dp[i+1][j+a] += dp[i][j];
            dp[i+1][j+a] %= MOD;
        }
    }
    
    cout << dp[n][s] << endl;
    
    return 0;
}