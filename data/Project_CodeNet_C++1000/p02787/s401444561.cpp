#include <stdio.h>
#include <limits.h>

int main()
{
    int h,n;
    int a[1000],b[1000];
    scanf("%d%d",&h,&n);
    for(int i=0;i<n;i++)scanf("%d%d",&a[i],&b[i]);

    int dp[20001];for(int i=0;i<=20000;i++) dp[i]=-1;
    dp[0]=0;
    for(int i=0;i<h;i++)
    {
        if(dp[i]==-1)continue;
        for(int j=0;j<n;j++)
        {
            if(dp[i+a[j]]==-1)dp[i+a[j]]=dp[i]+b[j];
            else if(dp[i+a[j]]>dp[i]+b[j])dp[i+a[j]]=dp[i]+b[j];
        }
    }
    int min=INT_MAX;
    for(int i=h;i<=10000;i++)
    {
        if(dp[i]==-1)continue;
        else if(dp[i]<min)min=dp[i];
    }
    printf("%d\n",min);
}