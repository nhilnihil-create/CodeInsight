#include <bits/stdc++.h>
using namespace std;

int main() {
  double x1, y1, x2, y2, ans = 0;
  scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
  cout << fixed << setprecision(5);
  ans = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
  cout << sqrt(ans) << "\n";
}
