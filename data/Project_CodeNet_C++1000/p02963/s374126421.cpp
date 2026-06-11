#include <bits/stdc++.h>
#define ri register int
using namespace std;
const int rlen = 1 << 20 | 5;
char buf[rlen], *ib = buf, *ob = buf;
#define gc() (((ib == ob) && (ob = (ib = buf) + fread(buf, 1, rlen, stdin))), ib == ob ? -1 : *ib++)
#define pb push_back
#define rez resize
#define ppp pop_back
inline int read() {
  static int ans;
  static char ch;
  for (ans = 0, ch = gc(); !isdigit(ch); ch = gc());
  while (isdigit(ch)) ans = ((ans << 2) + ans << 1) + (ch ^ 48), ch = gc();
  return ans;
}
inline int Read(char *s) {
  static int top;
  static char ch;
  for (ch = gc(), top = 0; !isalpha(ch); ch = gc());
  while (isalpha(ch)) s[++top] = ch, ch = gc();
  return top;
}
typedef long long ll;
typedef pair <int, int> pii;
#define fi first
#define se second
inline ll readl() {
  static ll ans;
  static char ch;
  for (ans = 0, ch = gc(); !isdigit(ch); ch = gc());
  while (isdigit(ch)) ans = ((ans << 2) + ans << 1) + (ch ^ 48), ch = gc();
  return ans;
}
template <typename T> inline void exgcd(T a, T b, T &x, T &y) {
  if (!b) { x = 1, y = 0; return; }
  exgcd(b, a - a / b * b, y, x), y -= a / b * x;
}
namespace modular {
  const int mod = 998244353;
  int ret;
  inline int add(int a, int b) { return a < mod - b ? a + b : a - mod + b; }
  inline int dec(int a, int b) { return a < b ? a - b + mod : a - b; }
  inline int mul(int a, int b) { return (ll) a * b % mod; }
  inline void Add(int &a, int b) { a = a < mod - b ? a + b : a - mod + b; }
  inline void Dec(int &a, int b) { a = a < b ? a - b + mod : a - b; }
  inline void Mul(int &a, int b) { a = (ll) a * b % mod; }
  inline int ksm(int a, int p) { for (ret = 1; p; p >>= 1, Mul(a, a)) (p & 1) && (Mul(ret, a), 1); return ret; }
  inline int fix(int x) {
    x <= -mod || x >= mod ? x %= mod : 0;
    return x < 0 ? x + mod : x;
  }
  inline int Inv(int a) {
    static int x, y;
    return exgcd(a, mod, x, y), fix(x);
  }
}  using namespace modular;
int a1 = 0, b1 = 0, a2 = 1000000000, b2 = 1, a3, b3;
ll S;
int main() {
  #ifdef ldxcaicai
  freopen("lx.in", "r", stdin);
  #endif
  S = readl();
  a3 = a2 - ((S - 1) % a2 + 1);
  b3 = (S - 1) / a2 + 1;
  cout << a1 << ' ' << b1 << ' ' << a2 << ' ' << b2 << ' ' << a3 << ' ' << b3 << '\n';
  return 0;
}