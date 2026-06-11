#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long int W, H, x, y, b=0;
  cin >> W >> H >> x >> y;
  double s;
  s = W * H /2.0;
  
  if (W == x*2 && H == y*2 ) {
    b++;
  }
  
  cout << s << " " << b << endl;
  return 0;
}
