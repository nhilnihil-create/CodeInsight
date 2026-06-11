#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=305;
int a[maxn];
int dp[maxn][maxn]={};
const int inf=1e18;
main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j)
            dp[i][j]=inf;
    }
    for(int i=1;i<=n;++i){
        dp[i][1]=a[i];
    }
    for(int i=1;i<=n;++i){
        for(int j=2;j<=n;++j){
            for(int k=1;k<=i-1;++k){
                dp[i][j]=min(dp[i][j],dp[k][j-1]+max(0ll,a[i]-a[k]));
            }
        }
    }
    int mi=inf;
    for(int i=1;i<=n;++i){
        mi=min(mi,dp[i][n-k]);
    }
    cout<<mi<<endl;
}
