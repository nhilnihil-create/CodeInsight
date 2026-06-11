#include <bits/stdc++.h>

const int MAX_N = 100005;
int64_t ans[MAX_N];

int main() {
  int64_t s = 0;
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; ++i) {
    int val;
    scanf("%lld", &val);
    ans[val]++;
    s += val;
  }
  int Q;
  scanf("%d", &Q);
  for (int i = 0; i < Q; ++i) {
    int64_t B, C;
    scanf("%lld %lld", &B, &C);
    s -= ans[B] * B;
    s += ans[B] * C;
    ans[C] += ans[B];
    ans[B] = 0;
    printf("%lld\n", s);
  }
}
