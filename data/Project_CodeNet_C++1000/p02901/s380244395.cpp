#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <climits>
#include <bitset>
#include <cmath>

template <typename C>
void print_container(const C &c, const std::string &name)
{
  std::cout << name << ": ";
  std::for_each(c.cbegin(), c.cend(),
                [](auto &x) { std::cout << x << ", "; });
  std::cout << std::endl;
}

template <typename Container, class T>
bool contains(const Container& c, T v)
{
  return std::find(c.begin(), c.end(), v) != c.end();
}

int main()
{
  const int64_t INF = std::pow(10, 5 + 3 + 1); // larger than max(a) * M
  int N, M;
  std::cin >> N >> M;

  const int n_ptn = std::pow(2, N);
  std::vector<std::vector<int64_t>> dp(M);
  for(int i=0; i<M; i++) {
    dp[i].assign(n_ptn, INF);
  }
  dp[0][0] = 0;

  for(int i=0; i<M; i++) {
    // read a, b
    int64_t a, b;
    std::cin >> a >> b;

    // read c[i] and update dp
    int s = 0;
    for(int j=0; j<b; j++) {
      int c;
      std::cin >> c;
      c--;  // 0-orient, 0-N

      s += 1 << c;
    }

    if(i==0) {
      dp[i][s] = a;
      continue;
    }

    for(int k=0; k<n_ptn; k++) {
      dp[i][k] = std::min(dp[i][k], dp[i-1][k]);
      dp[i][k|s] = std::min(dp[i][k|s], dp[i-1][k] + a);
    }
  }

  // for(int i=0 ;i<M; i++) {
  //   std::string name = "dp[" + std::to_string(i) + "]";
  //   print_container(dp[i], name);
  // }

  int64_t ret = dp[M-1][n_ptn-1];
  if(ret == INF) {
    ret = -1;
  }

  std::cout << ret << std::endl;
  return 0;
}
