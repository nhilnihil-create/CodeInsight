#include <iostream>
#include <string>

int main() {
  long long A;
  std::cin >> A;
  std::string tmp;
  while (true) {
    char c;
    std::cin >> c;
    if (c == '.')
      break;
    tmp += c;
  }
  char c;
  std::cin >> c;
  tmp += c;
  std::cin >> c;
  tmp += c;
  long long B = std::stoll(tmp);
  std::cout << (long long)(A * B / 100) << std::endl;
  return 0;
}