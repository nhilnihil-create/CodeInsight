#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[2005][2005];   // dp[i][j] 前 i 个人放了 j 个左边的
ll n,ma;
struct stu
{
    ll pos,w;
}a[2004];
bool cmp(stu u,stu v)
{
    return u.w>v.w;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i].w);
        a[i].pos=i;
    }
    sort(a+1,a+n+1,cmp);
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        memset(dp[i],-1,sizeof(dp[i]));
        for(int j=0;j<=i;j++)
        {
            // dp[i][j]=max(dp[i-1][j-1]+a[i].w*abs(a[i].pos-n+i-j-1),
            //             dp[i-1][j]+a[i].w*abs(a[i].pos-j));
            if(dp[i-1][j]!=-1){
            dp[i][j]=max(dp[i][j],dp[i-1][j]+a[i].w*abs(a[i].pos-n+i-j-1));    // 放在右边
            dp[i][j+1]=max(dp[i][j+1],dp[i-1][j]+a[i].w*abs(a[i].pos-j-1));    // 放在左边
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        ma=max(ma,dp[n][i]);
    }
    cout<<ma;
    return 0;
}
