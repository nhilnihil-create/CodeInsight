#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>

int testcase_ends() {
  size_t m;
  size_t nmin, nmax;
  scanf("%zu %zu %zu", &m, &nmin, &nmax);

  if (m == 0 && nmin == 0 && nmax == 0) return 1;

  std::vector<int> P(m);
  for (auto& pi: P) scanf("%d", &pi);

  std::sort(P.rbegin(), P.rend());
  size_t res = 0;
  int gap = 0;
  for (size_t i = m; i--;) {
    if (i > nmax) continue;
    if (i < nmin) break;
    if (gap < P[i-1]-P[i]) {
      gap = P[i-1]-P[i];
      res = i;
    }
  }
  printf("%zu\n", res);
  return 0;
}

int main() {
  while (!testcase_ends()) {}
}

