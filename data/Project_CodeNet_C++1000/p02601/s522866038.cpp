#include <bits/stdc++.h>
using namespace std; 
#define int int64_t
#define itn int
#define fi first
#define se second 
signed main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int a,b,c,k;
  cin>>a>>b>>c>>k;
  for(int i=0;i<k;i++){
    if(a>=b) b*=2;
    else if(b>=c) c*=2;
  }
  if(a<b&&b<c) cout<<"Yes\n";
  else cout<<"No\n";
}