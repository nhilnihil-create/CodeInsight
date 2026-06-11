#include <iostream>

typedef long long ll;

int main() {
  ll N, D;  std::cin >> N >> D;
  D *= D;
  int ans = 0;
  for (int i = 0; i < N; ++i) {
    ll x, y;  std::cin >> x >> y;
    ll d2 = x*x + y*y;
    if (d2 <= D)
      ans++;
  }
  std::cout << ans << "\n";

  return 0;
}
