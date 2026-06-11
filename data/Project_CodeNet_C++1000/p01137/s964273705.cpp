#include <iostream>

int main() {
  while (true) {
    int minv, e;
    std::cin >> e;
    if (e == 0) break;
    minv = e;
    
    for (int z = 0; z*z*z <= e; z++) {
      for (int y = 0; y*y+z*z*z <= e; y++) {
        int v = e - y*y -z*z*z + y + z;
        if (v < minv) minv = v;
      }
    }
    
    std::cout << minv << std::endl;
  }
  
  return 0;
}