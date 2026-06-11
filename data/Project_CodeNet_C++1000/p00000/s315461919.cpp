#include <iostream>

const int N = 9;

int main(void) {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      std::cout << i << "x" << j << "=" << i * j << std::endl;
    }
  }
   
  return 0;
}