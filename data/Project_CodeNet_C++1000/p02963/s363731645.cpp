#include <bits/stdc++.h>
using namespace std;

int main() {
  long long s;
  cin >> s;
  
  long long x, y, ma = pow(10, 9);
  y = (s + ma - 1) / ma, x = y * ma - s;
  
  cout << 0 << " " << 0 << " " << ma << " " << 1 << " " << x << " " << y << endl;
}