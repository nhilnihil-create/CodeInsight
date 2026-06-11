#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
#define pi 3.14159265359
#define int long long
#define pii pair<int,int>
const int mod=1e9+7;

int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

typedef tree<int,null_type,less<int>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_set;


int32_t  main()
{ 
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

   
   
  int n,k;
  cin>>n>>k;

  vector<int>v(n);
  vector<int>af(n),all(n);
  for(int i=0;i<n;i++)
  {
    cin>>v[i];
    for(int j=0;j<i;j++)
    {
      if(v[j]<v[i])all[i]++;
    }
  }
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      if(v[j]<v[i]){
        all[i]++; af[i]++;
      }
    }
  }

  int ans=0;
  for(int i=0;i<n;i++)
  {
    ans=(ans+(af[i]*k)%mod + ((k*(k-1)/2)%mod * all[i])%mod )%mod; 
  }
  cout<<ans<<"\n";
    
   
   

}

