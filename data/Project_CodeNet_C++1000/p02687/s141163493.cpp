#include <iostream>
#include <string>

int main() {
  std::string s; std::cin >> s;
  if (s[1] == 'B') std::cout << "ARC" << std::endl;
  else std::cout << "ABC" << std::endl;
  
  return 0;
}
