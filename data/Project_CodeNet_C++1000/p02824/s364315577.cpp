#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
#define FILL(a, n, x) memset((a), (x), sizeof ((a)[0]) * (n))
#define FILLA(a, x) memset((a), (x), sizeof (a))
#define COPY(a, n, b) memcpy((b), (a), sizeof ((a)[0]) * (n))
#define COPYA(a, b) memcpy((b), (a), sizeof (a))
using namespace std;

typedef pair<int, int> pii;
typedef long long li;
typedef unsigned long long lu;
const int inf = ~0U >> 2;
const li infl = ~0LLU >> 2;

template <class T> inline void Min(T &x, T y) { if (y < x) x = y; }
template <class T> inline void Max(T &x, T y) { if (y > x) x = y; }

const int mod = 1e9 + 7;
const int inv2 = mod + 1 >> 1;
inline int Add(int x) { return x >= mod ? x - mod : x; }
inline void Add(int &x, int y) { x += y; if (x >= mod) x -= mod; }
inline int Sub(int x) { return x < 0 ? x + mod : x; }
inline void Sub(int &x, int y) { x -= y; if (x < 0) x += mod; }
inline int Mul(int x, int y) { return (int)((li)x * y % mod); }
inline int Mul(int x, int y, int z) { return Mul(x, Mul(y, z)); }
int Pow(int x, int y) { int z = 1;
  for (; y; y >>= 1, x = Mul(x, x)) { if (y & 1) z = Mul(z, x); } return z; }
inline int Inv(int x) { return Pow(x, mod - 2); }
inline int Fix(li x) { x %= mod; if (x < 0) x += mod; return (int)x; }
inline int Fix(int x) { x %= mod; if (x < 0) x += mod; return x; }

// ----------------------------------------

const int maxn = 2e5;

int n, m, V, P;
int A[maxn];

bool Check(int i) {
  if (n - i <= P) return true;

  int h_start = n - (P - 1);
  if (h_start <= i) --h_start;
  int l_end = h_start - 1;
  if (l_end == i) --l_end;
  int lim = A[i] + m;

  li rest = (li)(P - 1) * m;
  for (int j = 0; j <= l_end; ++j) {
    if (j == i) continue;
    if (A[j] > lim) return false;
    rest += min(m, lim - A[j]);
  }
  return rest >= (li)m * (V - 1);
}

int main(void) {
  scanf("%d%d%d%d", &n, &m, &V, &P);
  for (int i = 0; i < n; ++i) {
    scanf("%d", A + i);
  }
  sort(A, A + n);
  int l = 0, r = n;
  while (r - l > 1) {
    int mid = l + r >> 1;
    if (Check(mid - 1)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  printf("%d\n", n - l);
  return 0;
}
