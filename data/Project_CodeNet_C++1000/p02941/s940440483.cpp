#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxnn=2e5+7;
const ll mod=4294967296;
const int inf=1e9+7;
ll a[maxnn];
ll b[maxnn];
ll sg[maxnn];
ll xg[maxnn];
priority_queue<pair<ll,ll>> que;
int main()
{
    ll n;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld",&b[i]);
        que.push(make_pair(b[i],i));
        xg[i]=i+1ll;
        sg[i]=i-1ll;
    }
    sg[1]=n;
    xg[n]=1;
    ll flag=0ll;
    ll cnt=0ll;
    while(!que.empty())
    {
        int x=que.top().second;
        que.pop();
        if(b[x]==a[x])
            continue;
        int y=sg[x];
        int z=xg[x];
        if(b[x]-b[y]-b[z]<a[x])
        {
            printf("-1\n");
            return 0;
        }
        int k=b[x]-a[x];
        int temp=k/(b[y]+b[z]);
        b[x]=(k%(b[y]+b[z]))+a[x];
        cnt+=temp;
        if(b[x]!=a[x])
           que.push(make_pair(b[x],x));

    }
    printf("%lld\n",cnt);
    return 0;
}

