#include <iostream>

int main() {
  int a, b, c, k;
  std::cin >> a >> b >> c >> k;
  while(k--) {
    if (b>=c) {
      c *= 2;
    }
    else if (a>=b) {
      b *= 2;
    }
    
  }
  if (a < b && b < c) {
    std::cout << "Yes";
  }
  else {
    std::cout << "No";
  }
}