#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n=305;
const ll inf=1e18;
int n,k,h[max_n];
ll dp[max_n][max_n];
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",h+i);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++)dp[i][j]=inf;
    }
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            for(int k=0;k<i;k++){
                dp[i][j]=min(dp[i][j],dp[k][j-1]+max(h[i]-h[k],0));
            }
        }
    }
    ll ans=inf;
    for(int i=0;i<=n;i++)ans=min(ans,dp[i][n-k]);
    printf("%lld\n",ans);
    return 0;
}