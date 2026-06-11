#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;
constexpr ll mod=1000000007;
constexpr int inf=1000000000;
constexpr ll linf=1000000000000000000;

int main(){
    string n;
    cin>>n;
    int sz=n.size();
    int dp[sz+1][2];
    fill(dp[0],dp[sz+1],inf);
    dp[0][0]=0;
    dp[0][1]=1;
    rep(i,sz){
        int d=n[i]-'0';
        dp[i+1][0]=min(dp[i][0]+d,dp[i][1]+10-d);
        if(d!=9)dp[i+1][1]=dp[i][0]+d+1;
        dp[i+1][1]=min(dp[i+1][1],dp[i][1]+9-d);
    }
    cout<<dp[sz][0]<<endl;
}
