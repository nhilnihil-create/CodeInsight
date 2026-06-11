#include <iostream>
#include <cmath>
using namespace std;

const long long C = 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 * 10 + 7;

long long power(int n, int r) {
  long long ret = 1;
  while (n > 0) {
    ret *= r;
    ret %= C;
    n--;
  }
  return ret;
}

int main() {
  long long N, ans {1};
  cin >> N;

  ans = power(N, 10);
  if (ans < 0) ans += C;
  ans -= power(N, 9);
  if (ans < 0) ans += C;
  ans -= power(N, 9);
  if (ans < 0) ans += C;
  ans += power(N, 8);
  ans %= C;
  cout << ans << endl;

  return 0;
}
