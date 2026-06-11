#include <iostream>
#include <vector>

int main() {
  int N, M; std::cin >> N >> M;
  const int MOD = 1000000007;
  std::vector<bool> issafe;
  
  issafe.assign(N+1, true);
  for (int i = 0; i < M; ++i) {
    int bs; std::cin >> bs;
    issafe[bs] = false;
  }
  
  std::vector<int> dp(N+1, 0); 
  dp[0] = 1; // 0段目の行き方は0通り
  if (issafe[1]) dp[1] = 1;
  // 貰うDP
  for (int i = 2; i <= N; ++i) {
    if (issafe[i-1]) dp[i] += dp[i-1];
    if (issafe[i-2]) dp[i] += dp[i-2];
    dp[i] %= MOD;
  }
  
  std::cout << dp[N] << std::endl; // N段目の階段k
}