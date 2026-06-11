#include <iostream>
#include <numeric>
using namespace std;
using ll = long long;

int n2(ll n) {
  int ret{};
  while (n % 2 == 0) {
    n /= 2;
    ++ret;
  }
  return ret;
}

int main() {
  ll N, M, a, r{1}, t{};
  cin >> N >> M;
  while (cin >> a) {
    if (!t) {
      t = n2(a);
    } else if (t != n2(a)) {
      r = M + 1;
      break;
    }
    r = lcm(r, a / 2);
    if (r > M) break;
  }
  cout << (M / r + 1) / 2 << endl;
}
