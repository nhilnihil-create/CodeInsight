#include <cstdio>
#define MAXN 200005

char s[MAXN];
int cnt[MAXN];

int main() {
  using ll = long long;
  int n, p;
  ll res = 0;
  scanf("%d%d%s", &n, &p, s);

  if (p == 2 || p == 5) {
    for (int i = 0; s[i]; ++i)
      if ((s[i] - 48) % p == 0) res += i + 1;
  } else {
    int t = 0, x = 1;
    for (int i = n - 1; i >= 0; --i) {
      ++cnt[t];
      t += (s[i] - 48) * x;
      t %= p;
      res += cnt[t];
      x = x * 10 % p;
    }
  }

  printf("%lld\n", res);

  return 0;
}
