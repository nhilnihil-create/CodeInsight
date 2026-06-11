#include <iostream>

typedef long long ll;
int N;
ll B[101], A[101];

int main() {
  std::cin >> N;
  for (int i = 1; i < N; ++i)
    std::cin >> B[i];

  ll sum = B[1];
  for (int i = 1; i < N-1; ++i)
    sum += (B[i] <= B[i+1] ? B[i] : B[i+1]);
  sum += B[N-1];

  std::cout << sum << "\n";

  return 0;
}
