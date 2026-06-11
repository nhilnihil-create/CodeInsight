#include <iostream>

int main()
{
  long long H, W;
  std::cin >> H >> W;
  if (H > 1 && W > 1) {
	  if ((H*W) % 2 == 0) std::cout << H*W / 2 << std::endl;
	  else std::cout << 1 + H*W / 2 << std::endl;
  }
  else std::cout << 1 << std::endl;
  return 0;
}
