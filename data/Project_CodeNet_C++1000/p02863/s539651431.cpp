#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <tr1/unordered_map>
using namespace std;
#define ll long long
#define re register
#define pb push_back
#define fi first
#define se second
const int N=1e6+10;
const int mod7=1e9+7;
const int mod=1e9+7;
void read(int &a)
{
    a=0;int d=1;char ch;
    while(ch=getchar(),ch>'9'||ch<'0')
        if(ch=='-')
            d=-1;
    a=ch^48;
    while(ch=getchar(),ch>='0'&&ch<='9')
        a=(a<<3)+(a<<1)+(ch^48);
    a*=d;
}
void read(ll &a)
{
    a=0;int d=1;char ch;
    while(ch=getchar(),ch>'9'||ch<'0')
        if(ch=='-')
            d=-1;
    a=ch^48;
    while(ch=getchar(),ch>='0'&&ch<='9')
        a=(a<<3)+(a<<1)+(ch^48);
    a*=d;
}
int f[3005][3005],dp[3005][3005];
int a[N],b[N];
int main()
{
    int n,T,ans=0;read(n),read(T);
    for(re int i=1;i<=n;i++) read(a[i]),read(b[i]);
    for(re int i=1;i<=n;i++)
    {
        for(re int j=1;j<=T-1;j++)
        {
            f[i][j]=f[i-1][j];
            if(j>=a[i]) f[i][j]=max(f[i][j],f[i-1][j-a[i]]+b[i]);
        }
    }
    for(re int i=n;i>=1;i--)
    {
        for(re int j=1;j<=T-1;j++)
        {
            dp[i][j]=dp[i+1][j];
            if(j>=a[i]) dp[i][j]=max(dp[i][j],dp[i+1][j-a[i]]+b[i]);
        }
    }
    for(re int i=1;i<=n;i++)
    {
        for(re int j=0;j<=T-1;j++)
        {
            ans=max(f[i-1][j]+dp[i+1][T-j-1]+b[i],ans);
        }
    }
    printf("%d\n",ans);
    return 0;
}