#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll> adj[200005];
ll cnt=0;
bool status[200005];
void dfs(int s)
{
    cnt++;
    status[s]=true;
    for(auto it:adj[s])
    {
        if(!status[it])
        {
            dfs(it);
        }
    }
}
void solve()
{
    ll n,m;
    cin>>n>>m;
    ll a,b;
    for(ll i=0;i<m;i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(status,false,sizeof(status));
    ll maxx=-1;
    for(int i=1;i<=n;i++)
    {
        if(!status[i])
        {
            cnt=0;
            dfs(i);
            maxx=max(maxx,cnt);
        }
    }
    cout<<maxx<<endl;
}
int main()
{
      solve();
}
