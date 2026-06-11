#include<iostream>
#include<cmath>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;
typedef long long int ll;
const ll maxn=(2*1e5)+2;
ll c;
void dfs(ll node,vector<ll>adj[],ll visited[])
{
    ll i;
    c++;
    visited[node]=1;
    for(i=0;i<adj[node].size();i++)
    {
        if(!visited[adj[node][i]])
        {
            dfs(adj[node][i],adj,visited);
        }
    }

}
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<ll>adj[n+1];
    ll i,x,y;
    for(i=0;i<m;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ll visited[n+1];
    for(i=0;i<=n;i++)
    {
        visited[i]=0;
    }
    ll ma=0;
    ll k=0;
    for(i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            c=0;
            dfs(i,adj,visited);
            if(c>ma)
                ma=c;
            k++;
        }
    }
    cout<<ma<<"\n";
    cerr<<"\nTime elapsed:"<< 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
