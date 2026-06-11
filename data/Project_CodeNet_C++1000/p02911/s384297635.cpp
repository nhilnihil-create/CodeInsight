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
  cin>>n>>k>>m;
  vector<ll>v(m);
  map<ll,ll>vis,pos;
  vector<ll>ans(n+1);
  for(ll i=1;i<=n;i++)ans[i]=k;
  
 // for(auto p:ans)cout<<p<<" ";
  //cout<<"\n";
  
  for(ll i=0;i<m;i++)cin>>v[i],pos[v[i]]++;
  
  //for(ll i=1;i<=n;i++)cout<<pos[i]<<" ";cout<<"\n";
  
  
  for(ll i=0;i<m;i++)
  {
      if(vis[v[i]]==0)
     ans[v[i]]=ans[v[i]]-(m-pos[v[i]]);
     vis[v[i]]++;
  }
  for(ll i=1;i<=n;i++)
  {
      //cout<<ans[i]<<" ";
      
      
      if(vis[i]==0)
      {
          if(m>=k)cout<<"No"<<"\n";
          else cout<<"Yes"<<"\n";
      }
      else if(ans[i]>0)cout<<"Yes"<<"\n";
      else cout<<"No"<<"\n";
  }
 //if(t>0)cout<<"\n";
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