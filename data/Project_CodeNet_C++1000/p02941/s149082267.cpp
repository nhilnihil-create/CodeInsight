#include <bits/stdc++.h>
using namespace std;
#define Maxn 200007
int n,a[Maxn],b[Maxn];
priority_queue<pair<int,int> >pq;
int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    while (!pq.empty()) pq.pop();
    for (int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
        if (b[i]!=a[i]) pq.push(make_pair(b[i],i));
    }
    long long ans=0LL;
    while (!pq.empty())
    {
        int i=pq.top().second;
        pq.pop();
        if (b[i]-b[(i+1)%n]-b[(i+n-1)%n]<a[i])
        {
            printf("%d\n",-1);
            return 0;
        }
        int tmp=b[(i+1)%n]+b[(i+n-1)%n],t;
        if (a[i]>=max(b[(i+1)%n],b[(i+n-1)%n]))
        {
            if (b[i]%tmp!=a[i]%tmp)
            {
                printf("%d\n",-1);
                return 0;
            }
            t=(b[i]-a[i])/tmp;
        } else t=(b[i]-max(b[(i+1)%n],b[(i+n-1)%n]))/tmp+1;
        b[i]-=t*tmp;
        if (b[i]<a[i])
        {
            printf("%d\n",-1);
            return 0;
        }
        if (b[i]!=a[i]) pq.push(make_pair(b[i],i));
        ans+=t;
    }
    printf("%lld\n",ans);
    return 0;
}