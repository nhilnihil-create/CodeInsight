#include<bits/stdc++.h>
#define ll long long int
#define pb(x) push_back(x)
using namespace std;
vector<ll> arr[200005];
ll vis[200005],dep[200005],ans[200005];
void bfs(ll src)
{
    queue<ll> q;
    q.push(src);
    dep[src]=0;
    vis[src]=1;
    while(!q.empty())
    {
        ll node=q.front();
        q.pop();
        for(ll child : arr[node])
        {
            if(vis[child]==0)
            {
                ans[child]=node;
                vis[child]=1;
                dep[child]=dep[node]=1;
                q.push(child);
            }
        }
    }
}
void dfs(ll node)
{
    vis[node]=1;
    for(ll child: arr[node])
    {
        if(vis[child]==0)
        dfs(child);
    }
}
int main()
{
    ll n,m;
    cin>>n>>m;
    for(ll i=0;i<n;i++)
    {
        ans[i]=INT_MAX;
    }
    for(ll i=0;i<m;i++)
    {
        ll x,y;
        cin>>x>>y;
        x--,y--;
        arr[x].pb(y);
        arr[y].pb(x);
    }
    ll c=0;
    for(ll i=0;i<n;i++)
    {
        if(vis[i]==0)
        {
            dfs(i);
            c++;
        }
    }
    if(c>1)
    {
        cout<<"No"<<endl;
        return 0;
    }
    else
    {
        cout<<"Yes"<<endl;
    }
    for(ll i=0;i<n;i++)
    {
        vis[i]=0;
    }
    bfs(0);
    for(ll i=1;i<n;i++)
    {
        cout<<ans[i]+1<<" "; 
    }
    cout<<endl;
    return 0;
}