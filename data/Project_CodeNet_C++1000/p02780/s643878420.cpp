#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_utility.hpp>
#include <utility>
#include <boost/foreach.hpp>
#include <cmath>

long long int N, K;
long long int p[2 * 100000 + 1];
long long int e[1000 + 1];
long double E[1000 + 1];
std::vector<long double> EE;
long double ans;

int main() {
  std::cin >> N >> K;
  for (long long int i = 1; i <= N; i++) {
    std::cin >> p[i];
  }

  // 各サイコロの期待値を求める
  for (long long int i = 1; i <= 1000; i++) {
    e[i] += e[i - 1] + i;
    E[i] = (long double)e[i] / i;
  }
  EE.push_back(0.0);
  for (long long int i = 1; i <= N; i++) {
    EE.push_back(E[p[i]]);
  }
  long double sum = 0.0;
  for (long long int i = 1; i <= K; i++) {
    ans += EE[i];
  }
  // K個連続した部分の期待値の合計を比べていく
  sum = ans;
  for (long long int i = 2; i + K - 1 <= N; i++) {
    sum -= EE[i - 1];
    sum += EE[i + K - 1];
    if (ans < sum) {
      ans = sum;
    }
  }

  std::cout << std::fixed << ans << std::endl;

  return 0;
}