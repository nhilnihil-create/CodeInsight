#include <iostream>
#include <cmath>

int main(){
   int N;
   std::cin >> N;
   double X;
   int cX = std::ceil(N / 1.08);
   int Nx = cX * 1.08;
   if (Nx == N){
      std::cout << cX << std::endl;
   } else{
      std::cout << ":(" << std::endl;
   }
}


