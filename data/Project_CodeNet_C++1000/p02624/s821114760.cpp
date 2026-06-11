#include <iostream>

typedef long long ll;

int main() {
  ll N; std::cin >> N;
  ll ans = 0;
  for (ll x = 1; x <= N; ++x) {
    ll y = N/x;
    ans += y * (y+1) * x / 2;
  }
  std::cout << ans << "\n";

  return 0;
}
