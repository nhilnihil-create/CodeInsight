#include <iostream>
#include <string>

int main() {
  std::string s, t;
  std::cin >> s >> t;
  int ans = 0;
  for (int i = 0; i < 3; ++i) ans += (s[i] == t[i]);
  std::cout << ans << std::endl;
}