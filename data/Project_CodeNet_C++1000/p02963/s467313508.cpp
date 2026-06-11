#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll A = 1e9;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll s;
  cin >> s;
  
  ll x1 = 0, y1 = 0, x2 = 1e9, y2 = 1, x3, y3;
  
  y3 = s / A + 1;
  x3 = A * y3 - s;
  
  if (s == 1e18) y2 = x3 = 0, y3 = 1e9;
  
  cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << '\n';
}