#include <vector>
#include <iostream>

int main(){
  int N;
  std::cin >> N;
  
  std::vector<int> ppl(N, 0);
  
  int num;
  while (std::cin >> num) ppl[num - 1]++;
  
  for (int i = 0; i < N; i++) std::cout << ppl[i] << std::endl;
  
  return 0;
}