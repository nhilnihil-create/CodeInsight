#include <iostream>
#include <string>

int main()
{
  std::string str;
  std::cin >> str;
  if (str == "SAT") std::cout << 1 << std::endl;
  else if (str == "FRI") std::cout << 2 << std::endl;
  else if (str == "THU") std::cout << 3 << std::endl;
  else if (str == "WED") std::cout << 4 << std::endl;
  else if (str == "TUE") std::cout << 5 << std::endl;
  else if (str == "MON") std::cout << 6 << std::endl;
  else std::cout << 7 << std::endl;
  return 0;
}