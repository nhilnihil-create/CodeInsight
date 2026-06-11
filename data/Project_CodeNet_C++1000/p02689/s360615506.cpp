#include <iostream>
#include <vector>

int main(){
  int N, M, a, b;
  std::cin >> N >> M;
  
  std::vector<long> Hs(N, 0);
  
  for (int i = 0; i < N; i++) std::cin >> Hs[i];
  
  std::vector<int> heighest(N, 1);
  
  for (int i = 0; i < M; i++){
    std::cin >> a >> b;
    a--;
    b--;
    if (Hs[a] > Hs[b]) heighest[b] = 0;
    else if (Hs[a] < Hs[b]) heighest[a] = 0;
    else {
      heighest[a] = 0;
      heighest[b] = 0;
    }
  }
  
  int answer = 0;
  for (int i = 0; i < N; i++) answer += heighest[i];
  
  std::cout << answer;
  
  return 0;
}