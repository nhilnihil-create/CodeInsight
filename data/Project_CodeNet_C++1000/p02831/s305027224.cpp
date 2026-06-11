#include <iostream>
#include <vector>
#include <numeric>

using ll = long long;
ll a, b;

int main() {
  std::cin >> a >> b;
  ll ans = (ll)std::lcm(a, b);
  std::cout << ans << std::endl;
}