#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
int main(void){
    ll h,w;
    cin>>h>>w;
    string s[h];
    rep(0,i,h)cin>>s[i];
    ll dp[h][w];
    rep(0,i,h)rep(0,j,w)dp[i][j]=10000000;
    dp[0][0]=(s[0][0]=='#')?1:0;
    rep(0,i,h){
        rep(0,j,w){
            if(i+1<h){
                if(s[i][j]=='.'&&s[i+1][j]=='#')dp[i+1][j]=min(dp[i][j]+1,dp[i+1][j]);
                else dp[i+1][j]=min(dp[i][j],dp[i+1][j]);
            }
            if(j+1<w){
                if(s[i][j]=='.'&&s[i][j+1]=='#')dp[i][j+1]=min(dp[i][j]+1,dp[i][j+1]);
                else dp[i][j+1]=min(dp[i][j],dp[i][j+1]);
            }
        }
    }
    cout<<dp[h-1][w-1];
}