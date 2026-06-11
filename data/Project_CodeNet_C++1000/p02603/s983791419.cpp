#include <bits/stdc++.h>
using namespace std; 
#define int int64_t
#define itn int
#define fi first
#define se second 
signed main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n,ans=1000;
  int a[100];
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=1;i<n;i++){
    if(a[i-1]<a[i]){
      ans=(ans/a[i-1])*a[i]+(ans%a[i-1]);
    }
  }
  cout<<ans<<"\n";
}
