#include <bits/stdc++.h>
#define Maxn 1000007
using namespace std;
int n;
int a[Maxn],p[Maxn];
bool calc(int x,int y)
{
    return ((p[x]-p[y]-p[x-y])==0);
}
int main()
{
    scanf("%d",&n);
    bool flag=false;
    for (int i=1;i<=n;i++)
    {
        char ch=getchar();
        while (ch<'1'||ch>'3') ch=getchar();
        a[i]=ch-'0'-1;
        if (a[i]==1) flag=true;
    }
    for (int i=1;i<=n;i++)
        if (i%2==1) p[i]=0; else p[i]=p[i/2]+1;
    for (int i=1;i<=n;i++)
        p[i]+=p[i-1];
    if (flag)
    {
        int ans=0;
        for (int i=1;i<=n;i++)
            if (calc(n-1,i-1)) ans^=(a[i]%2);
        printf("%d\n",ans);
    } else
    {
        int ans=0;
        for (int i=1;i<=n;i++)
            if (calc(n-1,i-1)) ans^=(a[i]/2);
        printf("%d\n",2*ans);
    }
    return 0;
}