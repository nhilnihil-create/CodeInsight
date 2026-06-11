#include <bits/stdc++.h>
using namespace std;
#define rapido ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"

void solve()
{
  int n;cin>>n;
  vector<int>arr(n);
  for(int i=0;i<n;i++)
  cin>>arr[i];
  
  vector<int>dec(n,1);
  for(int i=1;i<n;i++)
  {
      if(arr[i]<=arr[i-1])
      dec[i]=dec[i-1]+1;
      else
      dec[i]=1;
  }
  int ans=*max_element(dec.begin(),dec.end()) -1;
  cout<<ans<<endl;
}
int32_t main()
{
    rapido;
    int t;
    //cin>>t;
    t=1;
    while(t--)
    solve();
}