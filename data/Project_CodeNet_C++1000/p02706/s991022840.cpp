#include <iostream>

int main(){
   int N, M, A;
   std::cin >> N >> M;

   int sum = 0;
   for(int i=0; i<M; ++i) {
      std::cin >> A;
      sum += A;
   }
   std::cout << (sum <= N ? N - sum : -1) << std::endl;
   return 0;

}
