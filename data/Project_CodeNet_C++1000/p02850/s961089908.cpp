#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<ll,ll>>adj[100100];
ll color[100100];
ll visited[100100];
ll maxindex,maxi;
ll dfs(ll x,ll pcol)
{
    //cout<<x<<" x "<<pcol<<endl;
    //cout<<x<<"\n";
    visited[x]=1;
    ll cur=pcol+1;
    if(cur>maxi)
        cur=1;
    if(x==maxindex)
    {
        for(pair<ll,ll>p:adj[maxindex])
        {
            color[p.second]=cur;
            //cout<<p.second<<" "<<cur<<endl;
            dfs(p.first,cur);
            cur+=1;
            if(cur>maxi)
                cur=1;
        }
    }
    else
    {
        for(pair<ll,ll>p:adj[x])
        {
            if(visited[p.first]==0)
            {
                    color[p.second]=cur;
                    //cout<<p.second<<" "<<cur<<endl;
                    if(visited[p.first]==0)
                        dfs(p.first,cur);
                    cur+=1;
            }
            if(cur>maxi)
                cur=1;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll a,b;
    maxi=0;
    for(ll i=1;i<n;i++)
    {
        cin>>a>>b;
        adj[a].push_back(make_pair(b,i));
        adj[b].push_back(make_pair(a,i));
    }
    for(ll i=1;i<=n;i++)
    {
        if(adj[i].size()>maxi)
        {
            maxi=adj[i].size();
            maxindex=i;
        }
    }
    dfs(maxindex,0);
    //cout<<maxindex<<endl;
    cout<<maxi<<endl;
    for(ll j=1;j<n;j++)
    {
        cout<<color[j]<<endl;
    }
}