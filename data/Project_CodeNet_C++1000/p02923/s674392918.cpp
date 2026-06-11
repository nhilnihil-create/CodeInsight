#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional>
using namespace __gnu_pbds; 
using namespace std;



typedef tree<long long, null_type, less<long long>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    new_data_set; 
 
 
//defines
typedef long long ll;
typedef long double ld;

    
ll a,b,c,n,m,k,t=1;

void solve()
{ 
   cin>>n;
   vector<ll>v(n);
   for(ll i=0;i<n;i++)cin>>v[i];
   ll count=1,ans=0;
   for(ll i=1;i<n;i++)
   {
       if(v[i]<=v[i-1])count++;
       else
       {
           ans=max(ans,count);count=1;
       }
   }
   ans=max(ans,count);
   ans--;
   cout<<ans;
 if(t>0)cout<<"\n";
}

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  //cin>>t;
    while(t--)
    {
        solve();
    }
  //cout<<sum;
        
    return 0;
}