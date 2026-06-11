#include <bits/stdc++.h>

const int MAX_N = 200005;
int64_t as[MAX_N];

int main() {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    scanf("%lld", as + i);
  }
  std::sort(as, as + N);
  int64_t ans = 0;
  int count = N;
  int i = N - 1;
  while (count > 0) {
    ans += as[i] * std::min(2, count);
    count -= 2;
    i--;
  }
  ans -= as[N-1];
  printf("%lld\n", ans);
}
