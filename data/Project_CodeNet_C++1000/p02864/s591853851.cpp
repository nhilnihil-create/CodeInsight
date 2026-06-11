#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <tuple>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <list>

using namespace std;


void solve(long long N, long long K, std::vector<long long> H){
  H.push_back(0LL);
  vector<vector<vector<long long>>> dp(N+1, vector<vector<long long>>(N+1, vector<long long>(K+1, 0)));
  long long t;
  const long long MAX = N * 1000000000;
  dp[N][N][0] = H[N];
  for (int i = N-1; i >= 0; --i) {
    for (int j = N; j > i; --j) {
      for (int k = 1; k <= K; ++k) {
        dp[i][j][k] = dp[i+1][j][k-1];
      }
      dp[i][j][0] = MAX;
    }
    for (int k = 0; k <= K; ++k) {
      t = MAX;
      for (int j = N; j > i; --j) {
        t = min(dp[i+1][j][k] + max(H[i] - H[j], 0LL), t);
      }
      dp[i][i][k] = t;
    }
  }
  long long ret = MAX;
  for (int j = 0; j < N+1; ++j) {
    for (int k = 0; k <= K; ++k) {
      ret = min(dp[0][j][k], ret);
    }
  }
  std::cout << ret << std::endl;
}

int main(){
  long long N;
  scanf("%lld",&N);
  long long K;
  scanf("%lld",&K);
  std::vector<long long> H(N);
  for(int i = 0 ; i < N ; i++){
    scanf("%lld",&H[i]);
  }
  solve(N, K, std::move(H));
  return 0;
}
