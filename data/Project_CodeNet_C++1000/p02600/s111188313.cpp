#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main(){
  double x; cin >>x;
  x /= 400;
  int ans;
  if(x<1.5) ans = 8;
  else if(x<2) ans = 7;
  else if(x<2.5) ans = 6;
  else if(x<3) ans = 5;
  else if(x<3.5) ans = 4;
  else if(x<4) ans = 3;
  else if(x<4.5) ans = 2;
  else ans = 1;
  cout << ans << endl;
  return 0;
}