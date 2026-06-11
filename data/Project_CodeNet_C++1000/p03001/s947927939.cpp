#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main() {
  ll W, H, x, y;
  cin >> W >> H >> x >> y;
  
  printf("%lf", (double)W * (double)H /2);
  cout << " ";
  
  if (W % 2 == 0 && x == W/2 && H % 2 == 0 && y == H/2) {
    cout << 1 << endl;
  } else {
    cout << 0 << endl;
  }
    
}