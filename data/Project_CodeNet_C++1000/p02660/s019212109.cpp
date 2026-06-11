#include <bits/stdc++.h>

int64_t mem[45][45];
int64_t V;

int64_t dp(int64_t N, int64_t v) {
  if (N == 0) return 0;
  if (mem[N][v] != -1) return mem[N][v];
  int64_t best = -2;
  for (int64_t i = v + 1; i <= N; ++i) {
    if (dp(N - i, i) == -2) continue;
    best = std::max(dp(N - i, i) + 1, best);
  }
  mem[N][v] = best;
  return best;
}
std::unordered_map<int64_t, int64_t> m;


int main() {
  memset(mem, -1, sizeof(mem));
  scanf("%lld", &V);

  int64_t i = 2;
  int64_t count = 0;
  int64_t lim = int64_t(sqrt((long double)(V)) + 1000000);
  while (V != 1 && i <= lim) {
    if (V % i == 0) {
      m[i]++;
      V /= i;
    } else i++;
  }
  if (V != 1)
    m[V]++;
  for (auto kv : m) {
    count += dp(kv.second, 0);
  }
  printf("%lld\n", count);
}
