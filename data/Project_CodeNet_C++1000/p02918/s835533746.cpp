#include <iostream>
#include <vector>

void solve(int K, int N, std::string S)
{
  int score = 0;
  int num_group = 0;
  for (int i = 1; i < N; i++)
  {
    if(S[i]==S[i-1]){
      score++;
    }
  }
  int sum_score = std::min(score+2*K, N-1);
  std::cout << sum_score << std::endl;


}

int main(void)
{
  int K;
  int N;
  std::string S;
  std::cin >> N;
  std::cin >> K;
  std::cin >> S;
  solve(K,N,S);
  return 0;
}
