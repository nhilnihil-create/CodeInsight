#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
long long int dist[200005];
    long long int visited[200005];
int main()
{
    ll n,m;
    cin >> n >> m;
    vector< vector <ll > >adj(n);
    for(ll i=0;i<n-1;i++)
    {
        ll x,y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue <ll > q;
    for(ll i=0;i<m;i++)
    {
        ll temp,val;
        cin >> temp>>val;
        temp--;
        dist[temp]+= val;

    }
    q.push(0);
    while(!q.empty())
    {
        long long int f=q.front();
        q.pop();
        visited[f]=1;
        for(long long int i=0;i<adj[f].size();i++)
        {
            if(visited[adj[f][i]]==0)
            {
                dist[adj[f][i]]+=dist[f];
                q.push(adj[f][i]);
            }
        }
    }
    for(long long int i=0;i<n;i++)
    {
        cout << dist[i]<<" ";
    }
    
}
