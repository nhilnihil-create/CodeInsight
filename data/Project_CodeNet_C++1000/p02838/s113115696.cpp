#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod=1000000007;
int32_t main() {
  int n;
  cin>>n;
  vector<int>a(64,0);
  for(int j=0;j<n;j++){
    int x;
    cin>>x;
    bitset<64>c(x);
    for(int i=0;i<64;i++)
      if(c.test(i))
        a[i]++;
  }
  int ans=0;
  int j=1;
  for(int i=0;i<64;i++){
     if(i!=0) {
         j*=2;
         j%=mod;
     }
      ans=(ans+j*(a[i]*(n-a[i])%mod))%mod;
  }
  cout<<ans<<endl;
  
}