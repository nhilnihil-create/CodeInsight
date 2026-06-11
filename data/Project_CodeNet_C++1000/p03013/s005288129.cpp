#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

const int MX=100010,INF=1001001001,mod=1e9+7;
int dp[MX];
bool ng[MX];

int main(){
    int n,m;
    cin>>n>>m;
    set<int>se;
    rep(i,m){
        int a; cin>>a;
        ng[a]=true;
    }
    rep(i,MX)dp[i]=0;
    dp[0]=1;
    if(!ng[1])dp[1]=1;
    for(int i=2; i<=n; ++i){
        if(!ng[i-1])dp[i]+=dp[i-1];
        if(!ng[i-2])dp[i]+=dp[i-2];
        dp[i]%=mod;
    }
    cout<<dp[n]<<endl;
}