#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/detail/standard_policies.hpp>
// using namespace __gnu_pbds;
using namespace std;
// template <typename T>
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
//     tree_order_statistics_node_update>;
 
typedef long long int ll;
const ll N = 1e5 +9;
const ll p = 31;
// const ll m = 1e9 + 7;
const ll inf= 1e14;
const ll mod = 1e9+7;
#define x first
#define y second
#define pb push_back
#define mp make_pair
using pii = pair<ll, ll>;
ll powm(ll a, ll b) { a = a%mod;ll res = 1; while (b) { if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b >>= 1; } return res; }
std::vector<ll> adj[N],nadj[3*N];
ll dist[3*N];bool vis[3*N];

int main()
{   
    ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);                          

    ll T= 1;
    // cin >> T;
    while(T--){
        ll n,m,u,v;cin>>n>>m;
        for(int i = 0;i<n;i++){
            dist[3*i]=inf;
            dist[3*i +1]=inf;
            dist[3*i +2]=inf;
        }
        for(int i = 0;i<m;i++){
            cin>>u>>v;u--;v--;
            adj[u].pb(v);
            nadj[3*u].pb(3*v+1);
            nadj[3*u+1].pb(3*v+2);
            nadj[3*u +2].pb(3*v);
        }
        ll s,t;cin>>s>>t;s--;t--;
        memset(vis,0,sizeof(vis));
        dist[3*s] = 0;
        queue<ll> q;
        q.push(3*s);
        while(!q.empty()){
            ll v = q.front();
            q.pop();
            for(auto u:nadj[v]){
                if(vis[u])continue;
                vis[u] = 1;
                dist[u] = min(dist[u],dist[v]+1);
                q.push(u);
            }
        }
        ll ans= dist[t*3];
        if(ans==inf){
            cout<<-1;
        }
        else{
            cout<<ans/3<<'\n';
        }
        
        
    }
    return 0;
}   