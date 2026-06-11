#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mod 1000000007
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

int main()
{
  FAST/**/
   
   ll n,m;
   cin>>n>>m;
   
   ll c;
   cin>>c;
   
   pair<ll,ll> arr[c];
   rep(c)
        cin>>arr[i].ff>>arr[i].ss, arr[i].ff--, arr[i].ss--;
   map<pair<ll,ll>,ll> tot;
   map<ll,ll> row,col;
   rep(c)
   {
       row[arr[i].ff]++;
       col[arr[i].ss]++;
       tot[arr[i]]++;
   }
  
   ll ans = 0;
   map<ll,vector<ll>> ma;
   rep(c)
        ma[arr[i].ff].pb(col[arr[i].ss]);
   rep(c)
       ans = max(ans, row[arr[i].ff] + col[arr[i].ss] - tot[arr[i]]);
   multiset<ll> ms;
   rep(m)
        ms.insert(col[i]);
   rep(n)
   {
       auto it = ma.find(i);
       if(it!=ma.end())
       {
           autoit(it->ss,it1)
                ms.erase(ms.find(*it1));
       }
       
       if(ms.size()>0)
            ans = max(ans, row[i] + *ms.rbegin());
       if(it!=ma.end())
       {
           autoit(it->ss,it1)
                ms.insert(*it1);
       }        
   }
   
   cout<<ans;
   
   return 0;        
}  

  
          
   