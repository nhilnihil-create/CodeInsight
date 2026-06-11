#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;

ll dp[110][110];

int main(){
    ll h,w;cin>>h>>w;
    char c[110][110];
    rep(i,0,h)rep(j,0,w)cin>>c[i][j];
    ll x[2]={-1,0},y[2]={0,-1};
    rep(i,0,h)rep(j,0,w)dp[i][j]=1e7;
    if(c[0][0]=='#')dp[0][0]=-1;
    else dp[0][0]=0;
    rep(i,0,h){
        rep(j,0,w){
            rep(k,0,2){
                if(i+x[k]<0||j+y[k]<0)continue;
                
                if(c[i][j]=='#'&&dp[i+x[k]][j+y[k]]<0)dp[i][j]=(-1)*min(abs(dp[i][j]),(-1)*dp[i+x[k]][j+y[k]]);
                else if(c[i][j]=='#'&&dp[i+x[k]][j+y[k]]>=0)dp[i][j]=(-1)*min(abs(dp[i][j]),dp[i+x[k]][j+y[k]]+1);
                else if(c[i][j]=='.'&&dp[i+x[k]][j+y[k]]<0)dp[i][j]=min(dp[i][j],(-1)*dp[i+x[k]][j+y[k]]);
                else if(c[i][j]=='.'&&dp[i+x[k]][j+y[k]]>=0)dp[i][j]=min(dp[i][j],dp[i+x[k]][j+y[k]]);
            }
        }
    }

    cout<<abs(dp[h-1][w-1])<<endl;
}

    







