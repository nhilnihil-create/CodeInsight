#include <iostream>

std::string s;

int main() {
  std::cin >> s;
  if (s.back() == 's')
    s += "es";
  else
    s += "s";
  std::cout << s << "\n";

  return 0;
}
