#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t w,h;
  int x,y;
  cin>>w>>h>>x>>y;

  double ans = w/2.0*h;
  bool only;
  if(x*2==w && y*2==h) {
    only = false;
  }
  else only = true;
 
  cout<<ans<<' '<<(!only)<<endl;
  // cout<<fixed<<setprecision(10)<<ans<<' '<<(!only)<<endl;


  return 0;
}