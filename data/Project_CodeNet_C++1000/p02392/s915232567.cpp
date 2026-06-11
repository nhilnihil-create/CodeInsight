#include <iostream>

int main() {
  int a;
  int b;
  int c;
  std::cin >> a >> b >> c;

  bool flag = false;
  if(a < b) {
    if(b < c) {
      flag = true;
    }
  }
  if(flag) {
    std::cout << "Yes" << std::endl;
  }
  else {
    std::cout << "No" << std::endl;
  }

  return 0;
}