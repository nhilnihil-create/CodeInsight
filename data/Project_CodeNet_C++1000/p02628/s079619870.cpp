#include <iostream>
#include <algorithm>

int N, K, A[1001];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);

  std::cin >> N >> K;
  for (int i = 0; i < N; ++i)
    std::cin >> A[i];

  std::sort(A, A+N);

  int ans = 0;
  for (int i = 0; i < K; ++i)
    ans += A[i];

  std::cout << ans << "\n";

  return 0;
}
