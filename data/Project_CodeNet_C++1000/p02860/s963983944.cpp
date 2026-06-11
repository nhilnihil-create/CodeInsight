#include <iostream>
#include <string>

int main() {
  int n; std::cin >> n;
  std::string s; std::cin >> s;
  if (n % 2 == 1) {
    std::cout << "No" << std::endl;
    return 0;
  }
  bool ok = true;
  for (int i = 0; i < n/2; ++i) {
    if (s[i] != s[i+n/2]) ok = false;
  }
  if (ok) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
  
  return 0;
}