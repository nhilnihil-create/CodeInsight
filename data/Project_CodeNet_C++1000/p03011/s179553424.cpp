#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, m;
  cin >> a >> b >> c >> m;
  m = max(a, max(b, c));
  cout << a + b + c - m;
  return 0;
}