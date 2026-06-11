#include <bits/stdc++.h>
#define f(i, a, b) for (int i = a; i < (b); ++i)
#define rep(i, n) f(i, 0, n)
using namespace std;
using ll = long long;

int main(void) {
  double l;
  cin >> l;
  double a, b, c;
  a = b = c = l / 3;
  cout << fixed << setprecision(10);
  cout << a * b * c << '\n';
  return 0;
}