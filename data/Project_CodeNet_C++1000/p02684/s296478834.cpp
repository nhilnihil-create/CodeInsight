
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<ll>
#define vvll vector<vll>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define vb vector<bool>
#define pii pair<int, int>
#define vpli vector<pair<long long, int>>
#define deb(x) cout << "deb " << #x << " " << x << endl
#define all(x) x.begin(), x.end()
#define endl "\n"
int cycle_len;
vi ord;

void dfs(int s,vi& vis,vvi &adj,int& tot)
{
    tot++;
    for(int x : adj[s])
    {
        if(!vis[x])
        {
            ord.pb(x);
            vis[x] = vis[s]+1;
            dfs(x,vis,adj,tot);
        }
        else
        {
            cycle_len = vis[s] - vis[x]+1;
            return;
        }
        
    }
}
int dfs2(int s,vvi& adj,int k)
{
    if(k==0) return s+1;
    for(int x : adj[s])
    {
        return dfs2(x,adj,k-1);
    }
}
void solve()
{
    int n;
    ll k;
    cin>>n>>k;
    vvi adj(n);
    int u;
    for(int i=0;i<n;i++)
    {
        cin>>u;
        u--;
        adj[i].pb(u);
    }
    vi vis(n,0);
    vis[0] =1;
    int tot = 0;
    ord.pb(0);
    dfs(0,vis,adj,tot);
    int non_cyc = tot-cycle_len; 
    if(k>=tot)
    {
        k -= non_cyc;
        k = k%cycle_len;
        k += non_cyc;
    }
    cout<<ord[k]+1<<endl;
    //cout<<dfs2(0,adj,k); 
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //pre();
    int t = 1;
    //cin >> t;
    //cout<<__gcd(-5,0)<<endl;
    while (t--)
        solve();
    return 0;
}
