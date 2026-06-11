#include <bits/stdc++.h>

const int MAX_N = 200005;
int64_t as[MAX_N];

int main() {
  int64_t x = 0;
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    int64_t val;
    scanf("%lld", &val);
    x ^= val;
    as[i] = val;
  }
  for (int i = 0; i < N; ++i) {
    printf("%lld ", x ^ as[i]);
  }
  printf("\n");
}
