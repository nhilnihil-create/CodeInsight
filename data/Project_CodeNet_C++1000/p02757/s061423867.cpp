#include <iostream>
#include <vector>

int main() {
  int N, P;
  std::cin >> N >> P;
  std::string S;
  std::cin >> S;

  std::vector<int> m(N + 1, -1); // m[i] = S[i, N) % P
  m[N] = 0;
  int pow = 1;
  for (int i = N; i > 0; --i) {
    pow = pow * 10 % P;
    m[i - 1] = (m[i] + pow * (S[i - 1] - '0')) % P;
  }

  if (P == 2 || P == 5) {
    long long res = 0;
    for (int r = 1; r <= N; ++r) {
      if ((S[r - 1] - '0') % P == 0)
        res += r;
    }
    std::cout << res << std::endl;
    return 0;
  }

  std::vector<long long> count(P, 0);
  for (int i = 0; i < N + 1; ++i)
    count[m[i]] += 1;

  long long res = 0;
  for (int p = 0; p < P; ++p) {
    if (count[p] < 1)
      continue;
    res += count[p] * (count[p] - 1) / 2;
  }
  std::cout << res << std::endl;
}
