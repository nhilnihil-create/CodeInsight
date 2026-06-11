#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define sf scanf
#define pf printf
#define pi acos(-1)
#define time_save ios_base::sync_with_stdio(false); cin.tie(NULL);

ll vis[200005],n,m,mx,cnt=0;
vector<ll>vec[200005];
void dfs(ll src)
{
    vis[src]=1;
    cnt++;
    for(ll i=0;i<vec[src].size();i++)
    {
        ll v=vec[src][i];
        if(vis[v]==0)
        {
            vis[v]=1;
            //cnt++;
            dfs(v);
        }
    }
}
int main()
{
    //time_save;
    sf("%lld%lld",&n,&m);
    ll x,y;
    for(ll i=0;i<m;i++)
    {
        sf("%lld%lld",&x,&y);
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    for(ll i=1;i<=n;i++)
    {
        cnt=0;
        if(vis[i]==0)
        {
            dfs(i);
            mx=max(mx,cnt);
        }
    }
    cout<<mx<<endl;
    return 0;
}
