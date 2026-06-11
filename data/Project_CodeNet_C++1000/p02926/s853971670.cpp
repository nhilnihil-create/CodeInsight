/*

n=100

如果用x维正向的，就全用。
但是对于选择来说不独立

Δ1：二维距离，二维独立
顺序:
如果单独考虑最后的四种符号
是否可以将该问题化为二维距离最大的经典问题

如果第二维较小的话，可以一维花费一维收益

二维确定之后，完全相反的肯定不拿，完全相同的肯定拿
剩下的就是增加一个减小另一个

*/
#include<bits/stdc++.h>
#define y second
#define x first
using namespace std;
typedef long long ll;
const ll MAXN=205;
ll n,xsum[MAXN],ysum[MAXN];
pair<ll,ll>p[MAXN];
bool cmp(pair<ll,ll> a,pair<ll,ll> b)
{
    if(atan2(a.y,a.x)!=atan2(b.y,b.x))
    return atan2(a.y,a.x)<atan2(b.y,b.x);
    else return a.x<b.x;
}
ll len(ll detx,ll dety)
{
    return (detx*detx+dety*dety);
}
void solve()
{
    sort(p+1,p+1+n,cmp);

    for(ll i=1;i<=n;i++)
    {

        p[i+n]=p[i];
    }

    for(ll i=1;i<=2*n;i++)
    {
        xsum[i]=xsum[i-1]+p[i].first;
        ysum[i]=ysum[i-1]+p[i].second;
    }

    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=i;j<i+n;j++)
        {
            ll xx=xsum[j+1]-xsum[i];
            ll yy=ysum[j+1]-ysum[i];
            ans=max(ans,len(xx,yy));
        }
    }

    printf("%.15f\n",sqrt(ans));
}
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
    {
        scanf("%lld %lld",&p[i].first,&p[i].second);
    }
    solve();
}
/*
3
8 60
2 9 12 15 16 21 25 40
8 90
2 36 44 49 50 63 64 81
8 138600
40 2200 45 216 175 735 15 36

*/
