#include <iostream>

using ll = long long;

int const inf = 1000000000;

int main() {
  ll s;
  std::cin >> s;

  std::cout << 0 << " " << 0 << " ";
  if(s % inf == 0) {
    std::cout << inf << " " << s % inf << " ";
    std::cout << 1 << " " << s / inf;
  } else {
    std::cout << inf << " " << inf - s % inf << " ";
    std::cout << 1 << " " << s / inf + 1;
  }
  return 0;
}
