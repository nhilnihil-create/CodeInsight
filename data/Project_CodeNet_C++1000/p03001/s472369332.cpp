#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
  ll W, H, x, y;
  cin >> W >> H >> x >> y;
  
  double res = (double)(W)*H/2.0;
  cout << fixed << setprecision(10) << res << " ";
  
  if(2*x==W && 2*y==H) cout << 1 << endl;
  else cout << 0 << endl;
  
  
  return 0;
}