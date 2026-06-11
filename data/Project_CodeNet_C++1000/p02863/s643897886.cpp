#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
int dp1[6005][6005];
int dp2[6005][6005];
int w[6005],v[6005];
int n,t;
int max(int x,int y)
{
    if(x>=y)
        return x;
    else return y;
}
int main()
{
    scanf("%d%d",&n,&t);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&w[i],&v[i]);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=t-1;j++)
        {
            dp1[i][j]=dp1[i-1][j];
            if(j>=w[i])
                dp1[i][j] = max(dp1[i][j],dp1[i-1][j - w[i]] + v[i]);
        }
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=t-1;j++)
        {
            dp2[i][j]=dp2[i+1][j];
            if(j>=w[i])
                dp2[i][j]=max(dp2[i][j], dp2[i+1][j - w[i]] + v[i]);

        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=t-1;j++)
        {
            ans=max(ans, dp1[i-1][j] + dp2[i+1][t-1-j] + v[i]);
        }
    }
    printf("%d\n",ans);
}
