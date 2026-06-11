#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  // kx = 360n
  // k = 360n/x
  int g=__gcd(360,x);
  cout << 360/g << '\n';
  return 0;
}
