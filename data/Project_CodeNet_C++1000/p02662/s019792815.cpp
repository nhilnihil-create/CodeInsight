#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
static ll dp[3030][3030];
const ll mod=998244353;
int main(void){
    ll n,s;
    cin>>n>>s;
    ll a[n];
    rep(0,i,n)cin>>a[i];
    rep(0,i,3030)rep(0,j,3030)dp[i][j]=0;
    dp[0][0]=1;
    rep(1,i,n+1){
        rep(0,j,s+1){
            //cout<<j-a[i]<<":";
            if(j>=a[i-1])dp[i][j]=(2*dp[i-1][j]+dp[i-1][j-a[i-1]])%mod;
            else dp[i][j]=2*dp[i-1][j]%mod;
            //cout<<dp[i][j]<<endl;
        }
    }
    cout<<dp[n][s];
}
