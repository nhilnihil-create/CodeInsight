#include<bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mod 1000000007
#define mod2 998244353
#define ll long long int
#define pi 3.141592653589793238
const int N = 1e5 + 10;
vector<vector<int>> adj(N);
vector<bool> vis(N);
void dfs(ll u)
{
    vis[u]=true;
    for(auto v:adj[u])
        if(!vis[v])
            dfs(v);
}
int main(){
    FAST;
    ll t=1;
    // cin>>t;
    while(t--)
    {
        ll n,m,ans=0;
        cin>>n>>m;
        map<ll,ll> mp;
        for(ll i=0;i<m;i++)
        {
            ll x,y;
            cin>>x>>y;
            mp[x]++,mp[y]++;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for(ll i=1;i<=n;i++)
        {
            if(mp.find(i)==mp.end())
            {
                ans++;
                continue;
            }
            if(!vis[i])
                ans++,dfs(i);
        }
        cout<<ans-1;
    }
    return 0;
}
