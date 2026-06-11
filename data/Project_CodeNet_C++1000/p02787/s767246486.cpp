#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int const INF = 1e9;

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int H, N; std::cin >> H >> N;
  std::vector<int> A(N), B(N);
  std::vector<int> dp(H+1, INF);
  dp[0] = 0;
  for(int i = 0; i < N; ++i) {
    int A, B; std::cin >> A >> B;
    // use (A, B)
    for(int j = A; j <= H; ++j) dp[j] = std::min(dp[j], dp[j-A]+B);
    // over kill
    for(int j = A-1; j > 0; --j) dp[H] = std::min(dp[H], dp[H-j]+B);
  }
  fin(dp[H]);
  return 0;
}
