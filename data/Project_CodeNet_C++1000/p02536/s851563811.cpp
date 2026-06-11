#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pi 3.141592653589793238
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define mod 1000000007



    ll mod_pow(ll a,ll b,ll m)
    {
        ll res=1;
        while(b)
        {
            if(b&1)
                res=(res*a)%m;

            a=(a*a)%m;
            b>>=1;
        }
        return res;
    }
    vector<vector<ll>> adj(1000000);
    vector<bool> vis(1000000,false);

    void dfs(ll u)
    {
        vis[u]=true;
        for(auto x:adj[u])
            if(!vis[x])
                dfs(x);
    }

void solve()
{
    ll n,k;
    cin>>n>>k;
    for(ll i=0;i<k;i++)
    {
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ll ans=0;
    for(ll i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
            ans++;
        }
    }
    cout<<ans-1;
    return;
}

int main()
{
    FAST;
    #ifndef ONLINE_JUDGE
        freopen("input1.txt","r",stdin);
        freopen("output1.txt","w",stdout);
    #endif
    ll q;
    q=1;
    // cin>>q;
    while(q--)
        solve();
    return 0;
}
