#include <iostream>
#include <algorithm>

typedef long long ll;

int N;
ll A[200005];

int main() {
  std::cin >> N;
  for (int i = 0; i < N; ++i)
    std::cin >> A[i];
  std::sort(A, A+N, std::greater<int>());

  ll sum = -A[0];
  for (int i = 0; i < N; ++i)
    sum += A[i/2];

  std::cout << sum << "\n";

  return 0;
}
