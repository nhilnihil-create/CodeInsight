#include <iostream>
#include <cmath>

int main(){
   long long int H, W;
   std::cin >> H >> W;
   std::cerr << H*W << std::endl;
   if ((H == 1) || (W == 1)){
      std::cout << 1 << std::endl;
   } else if (H*W % 2 == 0)
      std::cout << H*W/2 << std::endl;
   else
      std::cout << H*W/2+1 << std::endl;
}

