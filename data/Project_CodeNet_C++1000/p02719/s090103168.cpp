#include <iostream>

int main(){
  unsigned long long N, K;
  std::cin >> N >> K;
  
  if (N >= K) N = N % K;
  
  if (N <= K - N) std::cout << N;
  else std::cout << K - N;
  
  return 0;
}