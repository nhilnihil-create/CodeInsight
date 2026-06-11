#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  scanf("%d", &n);
  double ans = 0.0;
  for (int i = 0; i < n; i++) {
    double a;
    scanf("%lf", &a);
    ans += 1.0 / a;
  }
  ans = 1.0 / ans;
  printf("%.10lf\n", ans);
}