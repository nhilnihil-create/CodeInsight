#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ll_MAX LONG_LONG_MAX
#define ll_MIN LONG_LONG_MIN
#define pi pair<int,int>
#define endl "\n"
#define MAXN 100005
#define mod 1000000007
using namespace std;

void solve()
{
    
}
ll find(ll x, vector<ll> & parent)
{
    if(parent[x] == x)
    {
        return x;
    }
    ll node = find(parent[x], parent);
    parent[x] = node;
    return node;
}
void union_set(ll x, ll y, vector<ll> & parent, vector<ll> &size)
{
    x = find(x, parent);
    y = find(y, parent);
    if(x != y)
    {
        if( size[x] < size[y] )
        {
            parent[x] = y;
            size[y] += size[x];
        }
        else
        {
            parent[y] = x;
            size[x] += size[y];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    solve();
    ll n,m;
    cin>>n>>m;
    vector<ll> parent(n + 1, -1);
    vector<ll> size(n + 1, 1);
    for(ll i=1; i<=n; i++)
    {
        parent[i] = i;
    }
    for(ll i=0; i<m; i++)
    {
        ll a,b;
        cin>>a>>b;
        union_set(a, b, parent, size);
    }
    ll ans = -1;
    for(ll i=1; i<=n; i++)
    {
        ans = max(ans, size[i]);
    }
    cout<<ans<<'\n';
}