#include <bits/stdc++.h>
using namespace std;

int main() {
  double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  double dx = abs(x1 - x2);
  double dy = abs(y1 - y2);
  cout << fixed << setprecision(4) << sqrt(dx * dx + dy * dy) << endl;
  return 0;
}

