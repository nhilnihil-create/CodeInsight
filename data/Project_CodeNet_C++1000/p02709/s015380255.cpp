#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int M=2010;
int n;
ll dp[M][M],ans;
struct elem{
    ll val,pos;
    bool operator<(elem tmp)
    {return val>tmp.val;}
}a[M];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i].val),a[i].pos=i;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        for(int L=0,R=n-i+2;R<=n+1;L++,R++)
        {
            dp[L+1][R]=max(dp[L+1][R],dp[L][R]+abs(L+1-a[i].pos)*a[i].val);
            dp[L][R-1]=max(dp[L][R-1],dp[L][R]+abs(R-1-a[i].pos)*a[i].val);
            //printf("%d %d %d %d\n",L,R,dp[L+1][R],dp[L][R-1]);
        }
    for(int i=1;i<n;i++)
        ans=max(dp[i][i+1],ans);
   // for(int i=0;i<=n+1;i++)
   // {
   //     for(int j=0;j<=n+1;j++)
   //         printf("%lld ",dp[i][j]);
   //     puts("");
   // }
    printf("%lld\n",ans);
    return 0;
}
