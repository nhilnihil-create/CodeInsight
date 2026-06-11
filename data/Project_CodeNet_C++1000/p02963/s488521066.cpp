#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int lim = 1'000'000'000;

int main() {
  ll n;
  cin >> n;

  int x1 = 0, y1 = 0;
  int x2 = lim, y2 = 1;
  int x3 = (n % lim == 0 ? 0 : lim) - n % lim;
  int y3 = (n % lim == 0 ? 0 : 1) + n / lim;

  printf("%d %d %d %d %d %d\n", x1, y1, x2, y2, x3, y3);
}