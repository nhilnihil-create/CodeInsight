#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rrep(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define reps(i, n) for (int i = 1; i <= int(n); i++)
#define rreps(i, n) for (int i = int(n); i >= 1; i--)
#define repc(i, n) for (int i = 0; i <= int(n); i++)
#define rrepc(i, n) for (int i = int(n); i >= 0; i--)
#define repi(i, a, b) for (int i = int(a); i < int(b); i++)
#define repic(i, a, b) for (int i = int(a); i <= int(b); i++)
#define all(a) (a).begin(), (a).end()
#define bit32(x) (1 << (x))
#define bit64(x) (1ll << (x))
#define sz(v) ((int) v.size())

using namespace std;

using i64 = long long;
using f80 = long double;
using vi32 = vector<int>;
using vi64 = vector<i64>;
using vf80 = vector<f80>;
using vstr = vector<string>;

void yes() { cout << "Yes" << endl; exit(0); }
void no() { cout << "No" << endl; exit(0); }
template <typename T> class pqasc : public priority_queue<T, vector<T>, greater<T>> {};
template <typename T> class pqdesc : public priority_queue<T, vector<T>, less<T>> {};
template <typename T> void amax(T &x, T y) { x = max(x, y); }
template <typename T> void amin(T &x, T y) { x = min(x, y); }
template <typename T> T exp(T x, i64 n, T e = 1) { T r = e; while (n > 0) { if (n & 1) r *= x; x *= x; n >>= 1; } return r; }
template <typename T> istream& operator>>(istream &is, vector<T> &v) { for (auto &x : v) is >> x; return is; }
template <typename T> ostream& operator<<(ostream &os, vector<T> &v) { rep(i, v.size()) { if (i) os << ' '; os << v[i]; } return os; }
void solve(); int main() { ios::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(16); solve(); return 0; }

const int INF = 1001001001;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

void solve() {
  int n;
  cin >> n;
  vi32 a(n);
  vi32 b(n);
  cin >> a >> b;
  using T = tuple<int, int>;
  pqdesc<T> q;
  rep(i, n) {
    q.emplace(b[i], i);
  }
  i64 ans = 0;
  while (sz(q)) {
    int _, i;
    tie(_, i) = q.top();
    q.pop();
    int prev = (i - 1 + n) % n;
    int next = (i + 1) % n;
    int div = b[prev] + b[next];
    int c = (b[i] - max(div, a[i]) + div - 1) / div;
    if (c <= 0) continue;
    b[i] -= div * c;
    ans += c;
    if (a[i] >= b[i]) continue;
    q.emplace(b[i], i);
  }
  if (a == b) {
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  }
}
