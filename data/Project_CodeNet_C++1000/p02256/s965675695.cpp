#include <iostream>

using namespace std;

// REQUIRES a >= b
static int FindGCD(int a, int b) {
  if (!b)
    return a;
  for (int d = b; d > 1; --d) {
    if (b % d == 0 && a % d == 0)
      return d;
  }
  return 1;
}

int main() {
  int x, y;
  cin >> x >> y;

  const int ret = x >= y ? FindGCD(y, x % y) : FindGCD(x, y % x);
  cout << ret << endl;
  return 0;
}