#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define fi first
#define se second
using namespace std;
short n,k;
int64_t dp[303][303],ans;
int a[303];
const int64_t vc=int64_t(1e17);
int main(){
    scanf("%hd%hd",&n,&k);
    for (short i=1;i<=n;++i) scanf("%d",&a[i]);
    k=n-k;
    if (k==0){printf("0");return 0;}
    for (short i=0;i<=n;++i)
    for (short j=0;j<=k;++j)
        dp[i][j]=vc;
    dp[0][0]=0;
    ans=vc;
    for (short i=1;i<=n;++i){
        for (short j=1,jj=min(i,k);j<=jj;++j){
            for (short z=0;z<i;++z)
                dp[i][j]=min(dp[i][j],dp[z][j-1]+max(0,a[i]-a[z]));
        }
        ans=min(ans,dp[i][k]);
    }
    printf("%lld",ans);
}
