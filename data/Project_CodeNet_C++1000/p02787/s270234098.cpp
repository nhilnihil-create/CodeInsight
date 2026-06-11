#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll dp[1010][10010];
const ll INF=1e18;

int main(){
    int h,n;
    cin>>h>>n;
    vector<int>a(n),b(n);
    rep(i,n)cin>>a[i]>>b[i];
    rep(i,1010)rep(j,10010)dp[i][j]=INF;
    rep(i,1010)dp[i][0]=0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<=h; ++j){
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
            dp[i+1][min(j+a[i],h)]=min(dp[i+1][min(j+a[i],h)],dp[i+1][j]+b[i]);
        }
    }
    cout<<dp[n][h]<<endl;
}