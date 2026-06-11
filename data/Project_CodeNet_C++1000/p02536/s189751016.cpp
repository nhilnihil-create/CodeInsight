#pragma GCC target ("avx2")
//#pragma GCC optimize "trapv"
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
#define input(a,n) for(ll i1=0;i1<n;i1++)cin>>a[i1]
#define ll long long
#define pi 2 * acos(0.0)
#define usll unordered_set<ll>
#define sll set<ll>
#define vll vector<ll>
#define mll map<ll,ll>
#define pll pair<ll,ll>
#define umll unordered_map<ll,ll>
#define S second
#define sz size()
#define all(v) v.begin(),v.end()
#define Y cout<< "YES"<< "\n"
#define N cout<< "NO"<< "\n"
#define F first
#define mp make_pair
#define pb push_back
#define pf push_front
#define ld long double
#define mod 1000000007
using namespace std;
ll vis[100005]={0};
void dfs(vll adj[],ll v)
{
    vis[v]=1;
    for(auto i:adj[v])
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            dfs(adj,i);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,m,ans=0;
    cin>>n>>m;
    vll adj[n+1];
    for(ll i=1;i<=m;i++)
    {
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    for(ll i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            ans++;
            dfs(adj,i);
        }
    }
    cout<<ans-1;
    return 0;
}
