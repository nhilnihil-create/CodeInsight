#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct mat {
    ll num[66];
    mat()
    {
        memset(num, 0, sizeof(num));
    }
    void add(ll a)
    {
        for (int i = 63; i >= 0; i--)
        {
            if (!((a >> i) & 1))
                continue;
            if (!num[i])
            {
                num[i] = a;
                break;
            }
            a ^= num[i];
        }
    }
}m;
#define MAXNUM 111111
#define rep(i,s,t) for(int i=s;i<t;i++)
ll num[MAXNUM];
int main()
{
    int n;scanf("%d",&n);
    ll sum=0;
    rep(i,1,n+1)scanf("%lld",&num[i]),sum^=num[i];
    rep(i,1,n+1)
    {
        rep(j,0,62)if(((sum>>j)&1)&&((num[i]>>j)&1))num[i]-=1ll<<j;
        m.add(num[i]);
    }
    ll res=sum,numnow=0;
    for(int i=62;i>=0;i--)
    {
        if(m.num[i])
        {
            if(!((numnow>>i)&1))numnow^=m.num[i];
        }
        if((numnow>>i)&1)res+=(1ll<<i)*2;
    }
    printf("%lld\n",res);
}