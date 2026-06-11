#include <algorithm>
#include <cstdio>
#include <vector>

static const size_t N_MAX = 1000000;
static int A[N_MAX];

int main() {
  size_t N;
  scanf("%zu", &N);
  for (size_t i = 0; i < N; i++)
    scanf("%d", A + i);
  std::vector<size_t> G;
  for (auto i = 1; unsigned((1 << i) - 1) <= N; i++)
    G.push_back((1 << i) - 1);
  std::reverse(G.begin(), G.end());
  int c = 0;
  for (auto&& g : G)
    for (size_t i = g; i < N; i++) {
      auto v = A[i];
      size_t j = i;
      while (j >= g && A[j-g] > v) {
        A[j] = A[j-g];
        j -= g;
        c++;
      }
      A[j] = v;
    }
  printf("%zu\n", G.size());
  for (size_t i = 0; i < G.size() - 1; i++)
    printf("%zu ", G[i]);
  printf("%zu\n", G.back());
  printf("%d\n", c);
  for (size_t i = 0; i < N; i++)
    printf("%d\n", A[i]);
  return 0;
}