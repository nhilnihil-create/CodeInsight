#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
ll h,w;
char c[110][110];
ll dp[110][110];
int main(){
    cin>>h>>w;
    rep(i,h)rep(j,w)cin>>c[i][j];
    rep(i,h)rep(j,w)dp[i][j]=1e17;
    dp[0][0]=(c[0][0]=='#');
    rep(i,h)rep(j,w){
        if(i+1<h)dp[i+1][j] = min(dp[i+1][j],dp[i][j]+(c[i][j]=='.'&&c[i+1][j]=='#'));
        if(j+1<w)dp[i][j+1] = min(dp[i][j+1],dp[i][j]+(c[i][j]=='.'&&c[i][j+1]=='#'));
    }
    cout<<dp[h-1][w-1]<<endl;
}