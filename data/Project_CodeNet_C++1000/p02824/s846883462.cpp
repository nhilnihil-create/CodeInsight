#include <bits/stdc++.h>
#define Maxn 100007
using namespace std;
int n,m,v,p;
int a[Maxn],b[Maxn];
bool check(int id)
{
    int tmp=a[id]+m;
    int now=0;
    for (int i=1;i<=n;i++)
        if (i!=id) b[++now]=a[i];
    long long res=1LL*p*m;
    for (int i=p;i<=now;i++)
    {
        if (b[i]>tmp) return false;
        res+=min(m,tmp-b[i]);
    }
    if (res>=1LL*m*v) return true;
    return false;
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&v,&p);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i]=-a[i];
    }
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
        a[i]=-a[i];
    int lx=1,rx=n;
    while (rx-lx>1)
    {
        int mid=(lx+rx)/2;
        if (check(mid)) lx=mid; else rx=mid;
    }
    if (check(rx)) printf("%d\n",rx); else printf("%d\n",lx);
    return 0;
}