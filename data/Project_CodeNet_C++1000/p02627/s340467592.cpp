#include <iostream>

int main()
{
  char c;
  std::cin >> c;

  std::string s = "A";
  if('a' <= c && c <= 'z') {
    s = 'a';
  } else if('A' <= c && c <= 'Z') {
    s = "A";
  }

  std::cout << s << std::endl;

  return 0;
}
