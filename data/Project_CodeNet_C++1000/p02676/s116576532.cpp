#include <iostream>

int main() {
  int k;
  std::string s;
  std::cin >> k >> s;
  if (s.size() <= k) {
    std::cout << s << std::endl;
    return 0;
  }
  std::string t = s.substr(0, k);
  std::cout << t << "..." << std::endl;
}