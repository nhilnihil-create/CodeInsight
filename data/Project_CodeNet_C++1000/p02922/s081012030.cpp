#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  // (a - 1) * x + a = b
  int x = (b - a) / (a - 1);
  if ((a - 1) * x + a < b)
    ++x;
  cout << x + 1 << '\n';   
  return 0;
}