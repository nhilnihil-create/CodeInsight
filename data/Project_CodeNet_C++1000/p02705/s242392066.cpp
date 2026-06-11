#include <iostream>
#include <iomanip>
#include <cmath>

int main(){
   const double pi = acos(-1);
   int R;
   std::cin >> R;

   std::cout << std::fixed << std::setprecision(10)  << 2. * pi * R << std::endl;
   return 0;
}
