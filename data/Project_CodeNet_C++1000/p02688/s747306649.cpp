#include <iostream>
#include <vector>

int main(){
  int N, K, d, s;
  std::cin >> N >> K;
  std::vector<int> S(N, 0);
  
  for (int i = 0; i < K; i++){
    std::cin >> d;
    for (int j = 0; j < d; j ++){
      std::cin >> s;
      S[s - 1]++;
    }
  }
  
  int answer = 0;
  for (int i = 0; i < N; i++){
    if (S[i] == 0) answer++;
  }
  
  std::cout << answer;
  

  return 0;
}