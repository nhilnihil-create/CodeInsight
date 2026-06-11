#include <bits/stdc++.h>

using namespace std;

//FILE *fi=freopen("1.txt","r",stdin);

int n,k,p[5005];
long long d[5005],c[5005];

void nhap()
{
    scanf("%d %d",&n,&k);
    for (int i=1;i<=n;++i)
    {
        scanf("%d",&p[i]);
    }
    for (int i=1;i<=n;++i)
    {
        scanf("%lld",&c[i]);
    }
}

void process()
{
    long long kq=-1e18;
    for (int i=1;i<=n;++i)
    {
        int vt=i,dem=1;
        while (vt!=i || dem==1)
        {
            d[dem]=d[dem-1]+c[p[vt]];
            vt=p[vt];
            dem++;
        }
        for (int i=1;i<=min(k,dem-1);++i)
        {
            long long ma=max(d[i],d[i]+d[dem-1]*((k-i)/(dem-1)));
            kq=max(kq,ma);
        }
    }
    cout<<kq;
}

int main()
{
    nhap();
    process();
    return 0;
}
