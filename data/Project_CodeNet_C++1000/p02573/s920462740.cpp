#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
#define pii pair<ll,ll>
#define inf 1000000000000000000
#define bpc(x) __builtin_popcountll(x)
#define autoit(x,it) for(auto it = x.begin(); it != x.end(); it++)
#define rep(n) for(ll i = 0; i < n; i++)
#define repi(i,n) for(ll i = 0; i < n; i++)

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 

#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 

using namespace std;
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());

ll find(ll x, ll par[])
{
    if(x == par[x])
        return x;
    return par[x] = find(par[x], par);
}
 
void unio(ll x, ll y, ll par[], ll rank[], ll siz[])
{
    x = find(x,par);
    y = find(y,par);
    if(x == y)
        return;
    if(rank[x]>rank[y])
    {
        siz[x]+=siz[y];
        rank[x] = max(rank[x], rank[y] + 1);
        par[y] = x;
    }
    
    else
    {
        siz[y]+=siz[x];
        rank[y] = max(rank[y], rank[x] + 1);
        par[x] = y;
    }
}

int main()
{
  FAST/**/
   
   ll n;
   cin>>n;
   
   ll m;
   cin>>m;
   
   ll par[n], rank[n], siz[n];
   rep(n)
       par[i] = i, rank[i] = 0, siz[i] = 1;
   
   rep(m)
   {
       ll a,b;
       cin>>a>>b;
       
       a--,b--;
       unio(a,b,par,rank,siz);
   }
   ll ans = 0;
   rep(n)
        ans = max(ans, siz[find(i,par)]);
   
   cout<<ans;
   
   return 0;        
}  

  
          
   