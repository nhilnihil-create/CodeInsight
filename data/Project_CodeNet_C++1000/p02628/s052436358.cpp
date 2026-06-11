#include <bits/stdc++.h>

const int MAX_N = 1005;
int N, K;
int as[MAX_N];

int main() {
  scanf("%d %d", &N, &K);
  for (int i = 0; i < N; ++i)
    scanf("%d", as + i);
  std::sort(as, as+N);
  int ans = 0;
  for (int i = 0; i < K; ++i)
    ans += as[i];
  printf("%d\n", ans);
}
