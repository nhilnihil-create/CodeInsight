#include <iostream>
#include <string>

int main() {
  std::string s, t; std::cin >> s >> t;
  bool ok = true;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] != t[i]) ok = false; 
  }
  if (ok) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
  
  return 0;
}