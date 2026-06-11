#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

#define pi acos(-1)
int main() {
  int a, b, h, m;
  cin >> a >> b >> h >> m;
  double ak = h*30 - m*5.5;
  double res = 0.0;

  res = sqrt(a*a + b*b - 2*a*b*cos(ak*pi/180));
  printf("%.20lf\n", res);
  return 0;
}

