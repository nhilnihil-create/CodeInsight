#include <cstdio>

const int MaxN = 1000000;

int N, K;
int A[MaxN + 5];

void init() {
  static char s[MaxN + 5];
  scanf("%d", &N);
  N--;
  scanf("%s", s + 1);
  for (int i = 1; i <= N; ++i)
    if (s[i] < s[i + 1]) A[i] = s[i + 1] - s[i];
    else A[i] = s[i] - s[i + 1];
}

void solve() {
  K = 1;
  for (int i = 1; i <= N; ++i)
    if (A[i] == 1) K = 0;
  for (int i = 1; i <= N; ++i)
    if (K == 1) A[i] >>= 1;
    else A[i] &= 1;
  int ans = 0;
  for (int i = 1; i <= N; ++i)
    if (A[i] == 1 && ((N - 1) & (i - 1)) == i - 1)
      ans ^= 1;
  printf("%d\n", ans << K);
}

int main() {
  init();
  solve();
  return 0;
}