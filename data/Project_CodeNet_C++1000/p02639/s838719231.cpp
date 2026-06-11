#include <iostream>

int main()
{
  int x[5];
  std::cin >> x[0] >> x[1] >> x[2] >> x[3] >> x[4];
  for (int i=0; i<5; i++) {
    if (x[i]==0) {
      std::cout << i+1 << std::endl;
      break;
    }
  }
  return 0;
}