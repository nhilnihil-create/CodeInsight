#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cassert>
#include <bitset>

//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;

//std::cout << std::fixed << std::setprecision(10)
//std::ios::sync_with_stdio(false);
constexpr long long MOD = 1000000007;

int dx[] = { 0, 1, 0, -1};
int dy[] = {-1, 0, 1,  0};

int main()
{
  int N, K, R, S, P;
  std::cin >> N >> K >> R >> S >> P;
  std::string T;
  std::cin >> T;
  std::vector<std::array<int, 3>> dp(N);
  auto getScore = [R, S, P](char c)
  {
    switch(c)
    {
    case 'r':
      return std::make_tuple(0, 0, P);
    case 's':
      return std::make_tuple(R, 0, 0);
    default:
      return std::make_tuple(0, S, 0);
    }
  };
  for(int i = 0; i < K; ++i)
  {
    auto score = getScore(T[i]);
    dp[i][0] = std::get<0>(score);
    dp[i][1] = std::get<1>(score);
    dp[i][2] = std::get<2>(score);
  }
  for(int i = K; i < N; ++i)
  {
    char c = T[i];
    dp[i][0] = std::max(dp[i - K][1], dp[i - K][2]);
    dp[i][1] = std::max(dp[i - K][0], dp[i - K][2]);
    dp[i][2] = std::max(dp[i - K][0], dp[i - K][1]);
    switch(c)
    {
    case 'r':
      dp[i][2] += P;
      break;
    case 's':
      dp[i][0] += R;
      break;
    default:
      dp[i][1] += S;
      break;
    }
  }
  int ans = 0;
  for(int i = 0; i < K; ++i)
  {
    auto& s = dp[N - i - 1];
    ans += std::max(s[0], std::max(s[1], s[2]));
  }
  std::cout << ans << std::endl;
  return 0;
}

