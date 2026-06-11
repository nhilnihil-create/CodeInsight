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
 k=__gcd(n,m);
 c=1;
 if(k%2==0)
 {
     c++;
     while(k%2==0)k/=2;
 }
 for(ll i=3;i*i<=k;i++)
 {
     if(k%i==0)
     {
         c++;
         while(k%i==0)k/=i;
     }
 }
 if(k>1)c++;
 cout<<c;
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