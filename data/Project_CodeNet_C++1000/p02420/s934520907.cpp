#include <iostream>
#include <string>

int main() {
  std::string str;

  int n, h;
  while(1) {
    std::cin >> str;
    if(str == "-") break;
    std::cin >> n;
    for(int i = 0; i < n; ++i) {
      std::cin >> h;
      str = str.substr(h, str.size() - h) + str.substr(0, h);
    }
    std::cout << str << std::endl;
  }

  return 0;
}