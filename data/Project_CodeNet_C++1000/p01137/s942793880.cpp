#include<iostream>
using namespace std;

int main() {
  int x, y, z, e, ans;
  while(cin >> e && e>0){
  ans = 1000000;
  for (z = 0; z*z*z <= e; z++)
    for (y = 0; (x = e - y*y - z*z*z) >= 0; y++)
      if (x + y + z < ans) ans = x + y + z;
  cout << ans << endl;
  }
  return 0;
}