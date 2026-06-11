#include <iostream>

int main(){
   int N, A;
   std::cin >> N;

   int count[N];
   std::fill(count, count+N, 0);
   for(int i=1; i<N; ++i){
      std::cin >> A;
      ++count[A-1];
   }
   for(int i=0; i<N; ++i)
      std::cout << count[i] << std::endl;

   return 0;
}
