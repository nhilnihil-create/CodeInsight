#include <string>
#include <iostream>

int main() {
  std::string str;
  std::cin >> str;
  std::string hitachi;
  for (int i = 0; i < str.size()/2; i++) hitachi += "hi";
  if (hitachi == str) std::cout << "Yes";
  else std::cout << "No";
  return 0;
}