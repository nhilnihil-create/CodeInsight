#include <iostream>
std::string str_repeat(char c, int n)
{
  std::string str = "";
  while (n--) {
    str += c;
  }
  return str;
}

int main(void)
{
  int h, w;
  while (std::cin >> h >> w) {
    if (h == 0 && w == 0) break;
    h -= 2;
    std::cout << str_repeat('#', w) << std::endl;
    while (h--) {
      std::cout << "#" << str_repeat('.', w - 2) << "#" << std::endl;
    }
    std::cout << str_repeat('#', w) << std::endl << std::endl;
  }
  return 0;
}