#include <iostream>

int main() {
  std::string s;
  std::cin >> s;
  
  for(int i = 0; i < s.length(); i++)
    std::cout << (s[i] == 'P' ? 'P' : 'D');
  
  std::cout << std::endl;
  return 0;
}
