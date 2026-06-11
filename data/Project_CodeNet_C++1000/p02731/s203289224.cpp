#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  double L;
  cin >> L;
  double v = 1.0;
  rep(i, 3) { v *= (L / 3.0); }
  cout << fixed << setprecision(7) << v << endl;
  return 0;
}