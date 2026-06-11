#include <cstdio>
#include <vector>

template <class T> void chmin(T &a, const T &b) {
  if (b < a)
    a = b;
}

template <class T> void chmax(T &a, const T &b) {
  if (a < b)
    a = b;
}

int main() {
  using u64 = unsigned long long;

  int n;
  scanf("%d", &n);
  std::vector<u64> a(n);
  u64 sum = 0;
  for (u64 &e : a) {
    scanf("%llu", &e);
    sum ^= e;
  }
  for (u64 &e : a)
    e &= ~sum;

  std::vector<u64> base;
  for (u64 e : a) {
    for (const u64 b : base)
      chmin(e, e ^ b);
    if (e != 0)
      base.push_back(e);
  }

  u64 ans = 0;
  for (const u64 b : base)
    chmax(ans, ans ^ b);

  printf("%llu\n", sum + ans * 2);
}
