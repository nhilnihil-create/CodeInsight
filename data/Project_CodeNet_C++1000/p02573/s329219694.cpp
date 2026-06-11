// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#include <bits/stdc++.h>  
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define pl pair<ll,ll>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vl vector<ll>
#define N 100005
#define mod 1000000007
ll parent[200005];
ll len[200005];

ll find(ll v)
{
    if(v==parent[v])
    return v;
    return parent[v]=find(parent[v]);
}
void add (ll u,ll v)
{
    ll a=find(u);
    ll b=find(v); 
    if(a==b)
    return;
    if(len[a]<len[b])
    swap(len[a],len[b]);
    len[a]+=len[b];
    parent[b]=a;
}
int main()
{
    ll n,m;cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        parent[i]=i;
        len[i]=1;
    }
    for(ll i=0;i<m;i++)
    {
        ll x,y;cin>>x>>y;
        add(x,y);
    }
    ll mx=0;
    for(ll i=1;i<=n;i++)
    mx=max(mx,len[i]);
    cout<<mx<<"\n";
    return 0;
}