#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define sf scanf
#define pf printf
#define pi acos(-1)
#define time_save ios_base::sync_with_stdio(false); cin.tie(NULL);

ll vis[100005],n,m;
vector<ll>vec[100005];

void dfs(ll n)
{
    if(vis[n]==1)
        return;
    vis[n]=1;
    for(ll i=0;i<vec[n].size();i++)
    {
        ll v=vec[n][i];
        if(vis[v]==0)
        {
            dfs(v);
        }
    }
}
int main()
{
    //time_save;
    cin>>n>>m;
    ll a,b;
    for(ll i=0;i<m;i++)
    {
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    ll cnt=0;
    for(ll i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            dfs(i);
            cnt++;
        }
    }
    cout<<cnt-1<<endl;
    return 0;
}
