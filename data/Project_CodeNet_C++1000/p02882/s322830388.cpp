#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int a, b, x;
  cin >> a >> b >> x;

  double v = a * a * b;
  double p, q;
  if (x * 2 <= v)
  {
    p = b;
    q = 2.0 * x / a / b;
  }
  else
  {
    p = (v - x) / (a * a);
    q = a / 2.0;
  }

  printf("%.10f\n", atan(p / q) * 180 / M_PI);
  return 0;
}
