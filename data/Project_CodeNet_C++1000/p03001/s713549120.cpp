#include <bits/stdc++.h>
using namespace std;

int main() {
  double W, H, X, Y;
  cin >> W >> H >> X >>Y;
  double ans = W/2.00*H;
  int hoka = 0;
  if(X==W/2 && Y ==H/2)hoka =1;
  
  cout << ans << " " << hoka << endl;
}