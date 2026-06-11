#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const long double PI = 3.14159265358979323846264338327950L;

int main() {
  int a, b, h, m;
  cin >> a >> b >> h >> m;
  long double rad = 2 * PI *((long double)h / 12.0 + (long double)m / 60.0 / 12.0
                             - (long double)m / 60.0);
  long double ans = (long double)(a*a+b*b)-(long double)(2*a*b)*cosl(rad);
  printf("%20.20Lf\n", sqrt(ans));
  return 0;
}
    