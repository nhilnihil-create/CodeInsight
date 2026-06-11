#include <bits/stdc++.h>
using namespace std;

int main() {
  int X, y = 0, z = 0, ans = 0;
  cin >> X;
  
  if (X/500 > 0) {
    y = X/500;
    ans += y*1000;
  }
  z = X - y*500;
  if (z/5 > 0) {
    z = z/5;
    ans += z*5;
  }
  
  cout << ans << endl;
}