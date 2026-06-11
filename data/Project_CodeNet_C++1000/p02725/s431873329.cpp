#include <iostream>
#include <vector>

int main(){
  int K, N; 
  std::cin >> K >> N;
  
  int A;
  int max_dist = 0;
  std::vector<int> As;
  
  for (int i = 0; i < N; i++){
    std::cin >> A;
    As.push_back(A);
    if (i != 0){
      if (As[i] - As[i - 1] > max_dist) max_dist = As[i] - As[i - 1];
    }
  }
  
  if (As[0] + K - As[N - 1] > max_dist) max_dist = As[0] + K - As[N - 1];
  
  std::cout << K - max_dist;
  
  return 0;
}