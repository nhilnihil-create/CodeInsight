#include<bits/stdc++.h>
using namespace std;
#define ll  unsigned long long
#define ld  long double
#define endl '\n'
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll MOD = (ll)1e9+7;
const double PI = 3.141592653589793238463;
const int MAXN = 1000030;
int s;
int dp[2005];
int dfs(int sum){
    if(sum==s)
    return 1;

    
    if(~dp[sum])
    return dp[sum];
    ll ans=0;
    for(int i=3;;i++){
        if(sum+i<=s){
            ans=(ans%MOD+dfs(sum+i)%MOD)%MOD;
        }else{
            break;
        }
        
    }
    return dp[sum]=ans%MOD;
    
}
int main() {
    cin>>s;
    memset(dp,-1,sizeof dp);
    cout<<dfs(0)%MOD;
    return 0;
}