#include <bits/stdc++.h>

using namespace std;

//FILE *fi=freopen("1.txt","r",stdin);

int n,p[10000001];

void init()
{
    for (int i=2;i*i<=1e7;++i)
    {
        if (!p[i])
        {
            p[i]=i;
            for (int j=i*i;j<=1e7;j+=i)
                if (!p[j]) p[j]=i;
        }
    }
    for (int i=2;i<=1e7;++i)
        if (!p[i]) p[i]=i;
}

long long solve(int x)
{
    if (x==1) return 1;
    if (p[x]==x) return 2;
    long long kq=1;
    while (x>1)
    {
        int dem=0,r=p[x];
        while (x%r==0)
        {
            dem++;
            x/=r;
        }
        kq*=(dem+1);
    }
    if (x>1) kq*=2;
    return kq;
}

void process()
{
    long long kq=0;
    for (int i=1;i<=n;++i)
    {
        kq+=(solve(i)*i);
    }
    cout<<kq;
}

int main()
{
    scanf("%d",&n);
    init();
    process();
    return 0;
}
