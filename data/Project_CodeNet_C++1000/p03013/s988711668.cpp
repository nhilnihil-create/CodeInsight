#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

const int mod=1e9+7;

int main(){
    int n,m;
    cin>>n>>m;
    vector<ll>dp(n+1);
    vector<bool>ng(n+1,false);
    rep(i,m){
        int a; cin>>a;
        ng[a]=true;
    }
    dp[n]=dp[n-1]=1;
    for(int i=n-2; i>=0; --i){
        if(ng[i])continue;
        if(!ng[i+1]&!ng[i+2])dp[i]=(dp[i+1]+dp[i+2])%mod;
        else if(ng[i+1]&ng[i+2])dp[i]=0;
        else if(!ng[i+1]&ng[i+2])dp[i]=dp[i+1];
        else dp[i]=dp[i+2];
    }
    cout<<dp[0]<<endl;
    return 0;
}