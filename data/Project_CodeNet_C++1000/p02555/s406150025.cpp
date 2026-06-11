#include <bits/stdc++.h>
#define N 2007
#define mod 1000000007ll
using namespace std;
typedef long long ll;

inline int rd() {
  int x = 0;
  bool f = 0;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = 1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = x * 10 + (c ^ 48);
    c = getchar();
  }
  return f ? -x : x;
}

int n, f[N];

int main() {
  n = rd();
  f[0] = 1;
  for (int i = 3; i <= n; ++i)
    for (int j = 3; j <= i; ++j)
      f[i] = (f[i] + f[i - j]) % mod;
  printf("%d\n", f[n]);
  return 0;
}
