#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll bfs(vector<vector<ll>> &adj,int n,int k)
{
    bool visit[n+1]={false}; visit[1]=true;
    ll mod=1000000007;
    ll ans=k;
    vector<ll> frontier{1};
    while(frontier.size())
    {
        vector<ll> next;
        for(auto u:frontier)
        {
            int t;
            if(u==1) t=k-1;
            else t=k-2;
            for(auto v:adj[u])
            {
                if(!visit[v])
                {
                    visit[v]=true;
                    ans=(ans*t)%mod;
                    t--;
                    next.push_back(v);
                }
            }
        }
        frontier=next;
    }
    return ans;

}

int main()
{
    ll n,i,j,k; cin>>n>>k;
    vector<vector<ll>> adj(n+1,vector<ll>());
    for(i=0;i<n-1;i++)
    {
        ll a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout<<bfs(adj,n,k);

}
