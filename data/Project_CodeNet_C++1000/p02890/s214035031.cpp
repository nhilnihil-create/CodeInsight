#include <bits/stdc++.h>

#define rep(i, n) for(int (i) = 0; i < (n); ++(i))

typedef long long ll;
const ll MOD = 1e9 + 7;

int main() {
  int N;
  std::cin >> N;
  std::vector<int> A(N);

  std::map<int, int> C;
  rep(i, N) {
    std::cin >> A[i];
    ++C[A[i]];
  }

  std::map<int, int> D;
  for(int i = 1; i <= N; ++i) {
    ++D[C[i]];
  }

  std::vector<ll> sum_D(N + 1), sum_kD(N + 1);
  sum_D[0] = D[0];
  sum_kD[0] = 0;
  for(int i = 1; i <= N; ++i) {
    sum_D[i] = sum_D[i - 1] + D[i];
    sum_kD[i] = sum_kD[i - 1] + i * D[i];
  }

  std::vector<ll> fs(N + 1);
  for(int X = 1; X <= N; ++X) {
    fs[X] = (sum_kD[X] + (sum_D[N] - sum_D[X]) * X) / X;
  }

  for(int K = 1; K <= N; ++K) {
    int x = 0;
    while(x + 1 <= N && K <= fs[x + 1]) {
      ++x;
    }
    std::cout << x << '\n';
  }

}
