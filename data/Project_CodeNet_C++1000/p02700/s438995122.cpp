#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int p = (c + b - 1) / b;
  int q = (a + d - 1) / d;
  cout << (p <= q ? "Yes" : "No") << endl;
}