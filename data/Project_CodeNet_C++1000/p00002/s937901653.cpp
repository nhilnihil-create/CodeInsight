#include <iostream>

int main() {
  int a, b;
  int i;

  for(;;) {

    std::cin >> a >> b;

    if( std::cin.eof() ) { break; }

    a = a + b;

    for(i = 1; i < 9; i++) {
      if(a <= 9) {
        break;
      }
      a /= 10;
    }
    std::cout << i << std::endl;

  }

  return 0;
}