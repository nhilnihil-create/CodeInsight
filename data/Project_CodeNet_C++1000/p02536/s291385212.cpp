//Jai Sai Ram 
// Please help me in every situation 
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
ll P=1e9+7;
vector<ll> adj[100001];
ll a[100001],b[100001];
ll find(ll x)
{
    if(a[x]==x)
    {
        return x;
    }
    return a[x]=find(a[x]);
}
ll unions(ll x,ll y)
{
    ll xp=find(x);
    ll yp=find(y);
    if(xp==yp)
    {
        return 0;
    }
    if(b[xp]>b[yp])
    {
        a[yp]=xp;
    }
    else 
    {
        a[xp]=yp;
        if(b[xp]==b[yp])
        b[yp]++;
    }
    return 1;
}
void solve()
{
    ll i,j,k,l,m,n,o,p,q,r,t,s;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        a[i]=i;
        b[i]=0;
    }
    for(i=0;i<m;i++)
    {
          cin>>j>>k;
          unions(j,k);
    }
    set<ll> se;
    for(i=1;i<=n;i++)
    se.insert(find(i));
    cout<<se.size()-1<<endl;
}
int main()
{
    ll t=1;
    ios_base::sync_with_stdio(false);
    cin.tie(0);

   //cin>>t;
   ll i=1;
    while(t--)
    {
      
        solve();
        i++;
    }
    return 0;
}
