#include <iostream>

int main()
{
  char c;
  std::cin >> c;
  if ('a' <= c && c <= 'z') std::cout << 'a' << std::endl;
  else std::cout << 'A' << std::endl;
  return 0;
}
