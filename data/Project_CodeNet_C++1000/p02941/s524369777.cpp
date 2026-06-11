#include<bits/stdc++.h>
#define ri register int
using namespace std;
const int rlen = 1 << 20 | 5;
char buf[rlen], *ib = buf, *ob = buf;
#define gc() (((ib == ob) && (ob = (ib = buf) + fread(buf, 1, rlen, stdin))), ib == ob ? -1 : *ib++)
inline int read() {
  static int ans;
  static char ch;
  for (ans = 0, ch = gc(); !isdigit(ch); ch = gc());
  while (isdigit(ch)) ans = ((ans << 2) + ans << 1) + (ch ^ 48), ch = gc();
  return ans;
}
typedef long long ll;
#define pb push_back
#define rez resize
#define ppp pop_back
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
  inline void Dec(int &a, int b) { a = a < b ? a - b + mod : a - b ; }
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
const int N = 2e5 + 5;
int n, a[N], b[N];
bool in[N];
inline bool check(int p) {
  int pre = p > 1 ? p - 1 : n;
  int suf = p < n ? p + 1 : 1;
  if (b[pre] + b[suf] <= b[p]) return 1;
  return 0; 
}
int main() {
  #ifdef ldxcaicai
  freopen("lx.in", "r", stdin);
  #endif
  n = read();
  for (ri i = 1; i <= n; ++i) a[i] = read();
  for (ri i = 1; i <= n; ++i) {
    b[i] = read();
    if (b[i] < a[i]) return cout << -1, 0;
  }
  queue <int> q;
  for (ri i = 1; i <= n; ++i) if (check(i)) q.push(i), in[i] = 1;
  ll res = 0;
  while (q.size()) {
    int x = q.front();
    q.pop(), in[x] = 0;
    int pre = x > 1 ? x - 1 : n;
    int suf = x < n ? x + 1 : 1;
    int ss = b[pre] + b[suf];
    int t = max(0, (b[x] - a[x]) / ss);
    if (!t && a[x] != b[x]) return cout << -1, 0;
    res += t, b[x] -= ss * t;
    if (!in[pre] && check(pre)) q.push(pre), in[pre] = 1;
    if (!in[suf] && check(suf)) q.push(suf), in[suf] = 1;
  }
  for (ri i = 1; i <= n; ++i) if (a[i] != b[i]) return cout << -1, 0;
  cout << res;
  return 0;
}