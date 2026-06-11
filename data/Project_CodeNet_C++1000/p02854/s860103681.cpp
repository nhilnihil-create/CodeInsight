#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

int main(){
   int N;
   std::cin >> N;
   std::vector<long long int> A(N);
   for (int i=0; i<N; i++){
      std::cin >> A.at(i);
   }
   int index = 0;
   long long int suml = 0;
   long long int sumr = 0;
   long long int suma = std::accumulate(A.begin(), A.end(), 0L);
   long long int min = suma;
   for (int i=0; i<N-1; i++){
      suml = suml + A.at(i);
      sumr = suma - suml;
      long long int d = std::abs(suml - sumr);
      if (d < min){
         min = d;
         index = i;
      }
   }
   std::cout << min << std::endl;

}

