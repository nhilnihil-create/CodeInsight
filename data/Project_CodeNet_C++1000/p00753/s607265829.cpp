#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;
#define REP(i, n) for (int i = 0; i < n; i++)

bool isPrime(int n) {
  if (n == 1)
    return false;
  int rn = floor(sqrt(n));
  for (int i = 2; i <= rn; i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}

int main() {
  int n = 0;
  while (cin >> n, n) {
    int ans = 0;
    for (int i = n + 1; i <= 2 * n; i++) {
      ans += isPrime(i) ? 1 : 0;
    }
    cout << ans << endl;
  }
}
