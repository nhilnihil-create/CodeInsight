
#include <iostream>





int main(int argc, const char * argv[]) {
  int x, count;
  while (1) {
    std::cin >> x;
    if (x == 0){
      break;
    } else {
      count ++;
      std::cout << "Case " << count << ": " << x << std::endl;
    }
  }

}