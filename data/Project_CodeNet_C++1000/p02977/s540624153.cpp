#include <bits/stdc++.h>
#define ld double
#define ull unsigned long long
#define ll long long
#define pii pair <int, int>
#define iiii pair <int, pii >
#define mp make_pair
#define INF 1000000000
#define MOD 1000000007
#define rep(i, x) for(int (i) = 0; (i) < (x); (i)++)
inline int getint() {
  int x = 0, p = 1; char c = getchar();	
  while (c <= 32) c = getchar();
  if (c == 45) p = -p, c = getchar();
  while (c > 32) x = x * 10 + c - 48, c = getchar();
  return x * p;
}
using namespace std;
//ruogu_alter
//
void p(int x, int y) {
  printf("%d %d\n", x, y);
}
int main() {
  int n = getint();
  int bit = 0;
  while ((1 << bit) < n) ++bit;
  if ((1 << bit) == n) return !printf("No\n");
  printf("Yes\n");
  p(1, n + 2); p(n + 2, 3);
  p(3, n + 1); p(n + 1, 2); p(2, n + 3);
  for (int i = 4; i + 1 <= n; i += 2) {
    p(i, n + 1); p(i, n + i + 1);
    p(i + 1, n + 1); p(i + 1, n + i);
  }
  if (!(n & 1)) {
    for (int i = 2; i <= n - 1; i++) if ((n ^ 1 ^ i) < n) {
      p(i, n);
      p(n ^ 1 ^ i, 2 * n);
      break;
    }
  }
  return 0;
}
