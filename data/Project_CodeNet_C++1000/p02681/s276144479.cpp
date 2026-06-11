#include <iostream>
#include <string>

int main()
{
  std::string a, b;
  std::cin >> a;
  std::cin >> b;
  int l = a.length();
  if (a == b.substr(0, l)) std::cout << "Yes" << std::endl;
  else std::cout << "No" << std::endl;
  return 0;
}