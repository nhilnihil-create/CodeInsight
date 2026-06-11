#include <iostream>
#include <string>

int main() {
  std::string s; std::cin >> s;
  bool ok = true;
  for (int i = 0; i < s.size(); ++i) {
    if (i%2 == 0 && s[i] == 'L') ok = false;
    if (i%2 == 1 && s[i] == 'R') ok = false;
  }
  if (ok) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
  
  return 0;
}