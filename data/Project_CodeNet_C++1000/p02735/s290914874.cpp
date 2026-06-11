#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int dp[110][110];

int main(){
    int h,w;
    cin>>h>>w;
    char fi[h][w];
    rep(i,h) rep(j,w) cin>>fi[i][j];
    rep(i,h) rep(j,w) dp[i][j]=INF;
    if(fi[0][0]=='#') dp[0][0]=1;
    else dp[0][0]=0;

    rep(i,h){
        rep(j,w){
            if(fi[i][j]=='.' && fi[i+1][j]=='#') dp[i+1][j]=min(dp[i+1][j],dp[i][j]+1);
            else dp[i+1][j]=min(dp[i+1][j],dp[i][j]);

            if(fi[i][j]=='.' && fi[i][j+1]=='#') dp[i][j+1]=min(dp[i][j+1],dp[i][j]+1);
            else dp[i][j+1]=min(dp[i][j+1],dp[i][j]);
        }
    }

    /*
    rep(i,h){
        rep(j,w){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/

    cout<<dp[h-1][w-1]<<endl;
} 
