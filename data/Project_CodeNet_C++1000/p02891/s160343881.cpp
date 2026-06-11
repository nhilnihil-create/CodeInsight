#include <bits/stdc++.h>
#define Maxn 507
#define inf 100007
using namespace std;
int n,p;
char s[Maxn];
int f[Maxn][30];
int main()
{
    scanf("%s",s+1);
    scanf("%d",&p);
    n=strlen(s+1);
    for (int i=n+1;i<=3*n;i++)
        s[i]=s[i-n];
    for (int i=1;i<=3*n;i++)
        for (int j=1;j<=26;j++)
            f[i][j]=inf;
    for (int i=1;i<=26;i++)
        f[1][i]=1;
    f[1][s[1]-'a'+1]=0;
    for (int i=2;i<=3*n;i++)
        for (int k=1;k<=26;k++)
        {
            int tmp=0;
            if (s[i]-'a'+1==k) tmp=0; else tmp=1;
            for (int t=1;t<=26;t++)
                if (k!=t) f[i][k]=min(f[i][k],f[i-1][t]+tmp);
        }
    int ans1=inf,ans2=inf,ans3=inf;
    for (int i=1;i<=26;i++)
    {
        ans1=min(ans1,f[n][i]);
        ans2=min(ans2,f[2*n][i]);
        ans3=min(ans3,f[3*n][i]);
    }
    long long ans=1LL*((p-1)/2)*(ans3-ans1);
    ans+=ans1;
    if (p%2==0) ans+=ans2-ans1;
    printf("%lld\n",ans);
    return 0;
}