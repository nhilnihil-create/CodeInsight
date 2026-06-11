#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF=1001001001;
int dp[1005][5000];

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>a(m),b(m),c(m);
    rep(i,m){
        cin>>a[i]>>b[i];
        rep(j,b[i]){
            int x; cin>>x;
            x--;
            c[i]|=(1<<x);
        }
    }
    rep(i,1005)rep(j,5000)dp[i][j]=INF;
    dp[0][0]=0;
    for(int i=0; i<m; ++i){
        for(int j=0; j<(1<<n); ++j){
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
            dp[i+1][j|c[i]]=min(dp[i+1][j|c[i]],dp[i][j]+a[i]);
        }
    }
    if(dp[m][(1<<n)-1]==INF)cout<<-1<<endl;
    else cout<<dp[m][(1<<n)-1]<<endl;
}