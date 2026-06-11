#include <iostream>
#include <string>

int main() {
  int k; std::cin >> k;
  std::string s; std::cin >> s;
  if (s.length() <= k) std::cout << s << std::endl;
  else std::cout << s.substr(0, k) << "..." << std::endl;
  
  return 0;
}