#define inf 9223372036854775807
#define ll long long
#define pii pair<ll,ll>
#define m_p  make_pair
#define ull unsigned long long
#define spd  ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
ll par[N];
ll cnt[N];
ll Findparent(ll a)
{
    if(par[a]==a)return a;

    par[a] = Findparent(par[a]);

    return par[a];
}

void Union(ll a,ll b)
{
    a = Findparent(a);
    b = Findparent(b);

    par[b] = a;
}
int main()
{
    spd
    ll n,m,a,b,ans=0,i;

    cin>>n>>m;

    for(i=1;i<=n;i++)
    {
        par[i] = i;
        cnt[i] = 1;
    }
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        ll x = Findparent(a);
        ll y = Findparent(b);
        if(x!=y)
        {
            if(cnt[par[a]]<cnt[par[b]])swap(a,b);
            cnt[par[a]]+=cnt[par[b]];
            Union(a,b);
        }
    }

    for(i=1;i<=n;i++)
    {
        ans = max(ans,cnt[i]);
    }

    cout<<ans<<endl;
}
