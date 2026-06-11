#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long W,H,x,y;
  cin >> W >> H >> x >> y;
  long long A;
  if (W%2 == 0 || H%2 == 0){
    A = W*H/2;
  }
  long double B;
  B = W*H/2;

  if (W%2 == 0 && H%2 == 0){
    if (W/2 == x && H/2 == y){
      cout << A << ' ' << 1 << endl;
    }
    else {
      cout << A << ' ' << 0 << endl;
    }
  }
  else if (W%2 == 0 || H%2 == 0){
    cout << A << ' ' << 0 << endl;
  }
  else {
    cout << fixed << setprecision(15) << B+0.5 << ' ' << 0 << endl;
  }
}