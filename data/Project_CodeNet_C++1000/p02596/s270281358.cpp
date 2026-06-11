#include <iostream>
#include <set>

int main() {
  int k;
  std::cin >> k;
  int x = 7 % k;
  int i = 1;
  std::set<int> s;
  while (s.find(x) == s.end()) {
    if (x == 0) {
      std::cout << i << std::endl;
      return 0;
    }
    s.insert(x);
    x = 10 * x + 7;
    x %= k;
    ++i;
  }
  std::cout << -1 << std::endl;
}
