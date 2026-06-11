#include <bits/stdc++.h>
using namespace std;

int main() {
  long W,H,x,y; cin >> W >> H >> x >> y;
  double area = W * H / 2.0;
  int way;
  if(x == W - x && y == H - y) {
    way =1;
  } else {
    way =0;
  }
  cout << fixed << setprecision(10) << area;;
  cout <<" " << way << endl;
}