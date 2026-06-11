#include <bits/stdc++.h>
using namespace std; 
#define int int64_t
#define itn int
#define fi first
#define se second 
signed main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int x,r=8;
  cin>>x;
  for(int i=0;i<8;i++){
    if(600+200*i<=x) r--;
  }
  cout<<r<<"\n";
}
