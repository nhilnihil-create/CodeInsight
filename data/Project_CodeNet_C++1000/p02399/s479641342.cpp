#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define shosu(n) setprecision(n)
using namespace std;
int main() {
  int a, b;
  double c, d, ans;
  cin >> a >> b;
  c = a;
  d = b;
  ans = c / d;
  cout << a / b << ' ' << a % b << ' ';
  printf("%.5lf\n", ans);
  return 0;
}