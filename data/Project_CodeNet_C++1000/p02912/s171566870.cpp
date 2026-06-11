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
  cin>>n>>m;
  priority_queue<ll>p;
  for(ll i=0;i<n;i++)cin>>k,p.push(k);
  for(ll i=1;i<=m;i++)
  {
      c=p.top();
      p.pop();
      p.push(c/2);
  }
  ll ans=0;
  while(!p.empty())
  {
      ans+=p.top();p.pop();
  }
  cout<<ans;
 if(t>0)cout<<"\n";
}

int32_t main()
{
#ifdef ONPC
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

 // cin>>t;
    while(t--)
    {
        solve();
    }
  //cout<<sum;
        
    return 0;
}