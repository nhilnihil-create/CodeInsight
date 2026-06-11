#include<bits/stdc++.h>
using namespace std;
typedef struct node node;
long long dp[2005][2005];
struct node
{
    long long val,pos;
};
node a[2005];
bool compare(const node &n1,const node &n2)
{
    return n1.val>n2.val;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i].val);
        a[i].pos=i;
    }
    sort(a+1,a+1+n,compare);
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<=i;j++)
    {
        if(dp[i-1][j]!=-1)
        {
            //cout<<i<<" "<<j<<endl;
            dp[i][j+1]=max(dp[i][j+1],dp[i-1][j]+a[i].val*(abs(a[i].pos-(j+1))));
            dp[i][j]=max(dp[i][j],dp[i-1][j]+a[i].val*abs(a[i].pos-(n-i+j+1)));
        }
    }
    long long ans=0;
    for(int j=0;j<=n;j++)
        {
            ans=max(ans,dp[n][j]);
            //cout<<dp[n][j]<<endl;
        }

    cout<<ans<<endl;
}
