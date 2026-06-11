#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  double ans = 0.0;
  if (n == 1) ans = 1;
  else if (n % 2 == 0) ans = (double)5/10;
  else {
    ans = (double)((n+1)/2) / n;
  }
  printf("%.10f\n", ans);
  return 0;
}