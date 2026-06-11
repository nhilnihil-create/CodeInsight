#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int64_t W, H ,x, y;
  
  cin >> W >> H >> x >> y;
  
  cout << fixed << setprecision(10);
  
  cout << double(W) * double(H) / 2 << " ";
  
  if (x * 2 == W && y * 2 == H) cout << 1 << endl;
  
  else cout << 0 << endl;
  
}