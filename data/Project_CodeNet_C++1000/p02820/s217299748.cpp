#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cstdio>
#include<cmath>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
using lint=long long;
int MOD=1000000007;

int r,s,p;

signed main(){
    int n,k;cin>>n>>k;
    cin>>r>>s>>p;
    string t;cin>>t;
    vector<vector<int>> dp(n+5,vector<int>(4,0));
    rep1(i,k){
        if(t[i-1]=='r')dp[i][3]=p;
        else if(t[i-1]=='s')dp[i][1]=r;
        else dp[i][2]=s;
    }
    for(int i=k+1;i<=n;++i){
        rep1(j,3){
            dp[i][j]=max(dp[i-k][(j+1)%3+1],dp[i-k][j%3+1]);
        }
        if(t[i-1]=='r')dp[i][3]+=p;
        else if(t[i-1]=='s')dp[i][1]+=r;
        else dp[i][2]+=s;
    }
    int res=0;
    for(int i=n;i>n-k;--i){
        int buf=0;
        rep1(j,3)buf=max(buf,dp[i][j]);
        res+=buf;
    }
    cout<<res<<"\n";
    return 0;
}