#include <bits/stdc++.h>
using namespace std;

int main() {
  double W, H;
  double x, y;
  cin >> W >> H >> x >> y;
  cout << W * H / 2 << " ";
  if(2 * x == W && 2 * y == H) {
    cout << 1 << endl;
  }
  else {
    cout << 0 << endl;
  }
}