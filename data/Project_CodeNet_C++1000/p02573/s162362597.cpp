#include<bits/stdc++.h>
#define fr(i,a,n) for(ll i=a;i<n;i++)
#define YES cout<<"YES"<<endl
#define all(v) v.begin(),v.end()
#define NO cout<<"NO"<<endl
#define pb(x) emplace_back(x)
#define fastio std::ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define vi vector<ll>
#define mi map<ll,ll>
#define pi pair<ll,ll>
#define what(x) cout<<#x<<" ="<<x<<endl;
using namespace std;
using ll =long long;
vi adj[200005],vis(200005);

ll dfs(ll u)
{
    ll cnt=0;
    vis[u]=1;
    cnt++;

    for(auto v:adj[u])
        if(vis[v]==0)cnt+=dfs(v);

    return cnt;

}

int main()
{
        ll n,m;
        cin>>n>>m;

        fr(i,0,m)
        {
            ll x,y;
            cin>>x>>y;

            adj[x].pb(y);
            adj[y].pb(x);


        }

        ll ans=0;

        fr(i,1,n+1)
        {
            ll s=0;

            if(vis[i]==0)s=dfs(i);
            ans=max(ans,s);
        }
        cout<<ans<<endl;


}


























