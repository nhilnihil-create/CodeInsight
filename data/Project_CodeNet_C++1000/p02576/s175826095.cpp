#include <bits/stdc++.h>
using namespace std; 
#define int int64_t
#define itn int
#define fi first
#define se second
#define mod 1000000007
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,x,t;
  cin>>n>>x>>t;
  if(n%x==0) cout<<n/x*t<<"\n";
  else{
    cout<<n/x*t+t<<"\n";
  }
  return 0;
}
