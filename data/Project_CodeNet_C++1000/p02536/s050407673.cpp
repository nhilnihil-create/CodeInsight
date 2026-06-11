/* ChampionsNeverFall :)*/
#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ff first
#define ss second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define mp make_pair
#define mod 1000000007
#define vll vector<ll>
#define vpll vector<pair<ll,ll> >
#define pll pair<ll,ll>
#define f(n) for(ll i=0;i<n;i++)
#define pb push_back
#define iPair pair<ll, pair<ll,ll>>
#define en '\n'
typedef long long ll;
typedef long double ld;
#define PI 2*acos(0.0);
ll extendedGcd(ll a, ll b, ll & x, ll & y);
void addEdge(vector<ll> adj[], ll u, ll v);
void DFSUtil(ll u, vector<ll> adj[],vector<bool> &visited);
void DFS(vector<ll> adj[], ll V,ll start=0);
ll logg(ll x);
ll pw(ll x,ll y);
ll lcm(ll a,ll b);
vll adj[100005];
bool vis[100005];
ll n;
ll connected=0;
void dfs(int x)
{
    vis[x]=true;
    for(auto it: adj[x])
    {
        if(vis[it]==false)
        {
           dfs(it);
        }
    }
}
void cnnct()
{
    rep(i,1,n+1)
    {
        if(vis[i]==false)
        {
            //cout<<i<<en;
            dfs(i);
            connected++;
        }
    }
}
int main()
{
    IOS
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ll t=1;
    //cin>>t;
    while(t--)
    {
        ll m,x,y;
        memset(vis,false,sizeof vis);
        cin>>n>>m;
        f(m)
        {
            cin>>x>>y;
            adj[x].pb(y);
            adj[y].pb(x);
        }
        cnnct();
        cout<<connected-1<<en;
    }
    return 0;
}
ll lcm(ll a,ll b)
{
    ll temp=((a*b)/__gcd(a,b));
    return temp;
}
ll pw(ll x,ll y)
{
    ll temp = 1;
    x = x % mod;
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1)
            temp = (temp*x) % mod;
        y = y>>1;
        x = (x*x) % mod;
    }
    return temp;
}
ll logg(ll x)
{
    ll ans=0;
    ll temp=1;
    while(temp<=x)
    {
        temp*=2;
        ans++;
    }
    if(temp>x)
        ans--;
    return ans;
}
ll extendedGcd(ll a, ll b, ll & x, ll & y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1;
    ll d = extendedGcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}


