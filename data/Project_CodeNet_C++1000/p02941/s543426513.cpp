#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],b[N];
struct node
{
    int x,pos;
    node(int x=0,int pos=0):x(x),pos(pos){}
    bool operator<(const node&o)const
    {
        return x<o.x;
    }
};
priority_queue<node>q;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]),q.push(node(b[i],i));
    long long ans=0;
    while(!q.empty())
    {
        int u=q.top().pos;q.pop();
        if(b[u]==a[u]) continue;
        int l=u-1,r=u+1;
        if(l==0) l=n;
        if(r==n+1) r=1;
        int now=max(a[u],max(b[l],b[r]));
        if((b[u]-now)/(b[l]+b[r])>0)
        {
            ans+=(b[u]-now)/(b[l]+b[r]);
            b[u]-=(b[u]-now)/(b[l]+b[r])*(b[l]+b[r]);
        }
        else
        {
            b[u]-=b[l]+b[r];
            ans++;
        }
        if(b[u]<a[u])
        {
            printf("-1\n");return 0;
        }
        if(b[u]!=a[u])
            q.push(node(b[u],u));
    }
    printf("%lld\n",ans);
}
