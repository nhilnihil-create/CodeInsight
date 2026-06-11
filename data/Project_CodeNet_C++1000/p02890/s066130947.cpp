#include <cstdio>
const int maxn = 300010;

int a[maxn], g[maxn], f[maxn];
int s[maxn], t[maxn], p[maxn];

int main() {
  int n, k;
  scanf("%d", &n); k = n;
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  for (int i = 1; i <= n; ++i) g[a[i]]++;
  for (int i = 1; i <= n; ++i) f[g[i]]++;
  for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + i * f[i];
  for (int i = n; i >= 1; --i) t[i] = t[i + 1] + f[i];
  for (int i = 1; i <= n; ++i) p[i] = (s[i] + i * t[i + 1]) / i;
  for (int i = 1; i <= n; ++i) {
    while (k && i > p[k]) --k;
    printf("%d\n", k);
  }
  return 0;
}