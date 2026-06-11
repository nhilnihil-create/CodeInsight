#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rrep(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define reps(i, n) for (int i = 1; i <= int(n); i++)
#define rreps(i, n) for (int i = int(n); i >= 1; i--)
#define repc(i, n) for (int i = 0; i <= int(n); i++)
#define rrepc(i, n) for (int i = int(n); i >= 0; i--)
#define repi(i, a, b) for (int i = int(a); i < int(b); i++)
#define repic(i, a, b) for (int i = int(a); i <= int(b); i++)
#define each(x, y) for (auto &x : y)
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

inline void yes() { cout << "Yes" << endl; exit(0); }
inline void no() { cout << "No" << endl; exit(0); }
template <typename T> class pqasc : public priority_queue<T, vector<T>, greater<T>> {};
template <typename T> class pqdesc : public priority_queue<T, vector<T>, less<T>> {};
template <typename T> inline void amax(T &x, T y) { x = max(x, y); }
template <typename T> inline void amin(T &x, T y) { x = min(x, y); }
template <typename T> inline T exp(T x, i64 n, T e = 1) { T r = e; while (n > 0) { if (n & 1) r *= x; x *= x; n >>= 1; } return r; }
template <typename T> istream& operator>>(istream &is, vector<T> &v) { each(x, v) is >> x; return is; }
template <typename T> ostream& operator<<(ostream &os, vector<T> &v) { rep(i, v.size()) { if (i) os << ' '; os << v[i]; } return os; }
void solve(); int main() { ios::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(16); solve(); return 0; }

template <typename T>
struct SegmentTree {
  using F = function<T(T, T)>;
  vector<T> v;
  F f;
  T e;
  int n;
  SegmentTree(int size, F f, T e) : f(f), e(e) {
    n = 1;
    while (n < size) n <<= 1;
    v.resize(n * 2, e);
  }
  void set(int k, T x) {
    v[k + n] = x;
  }
  void build() {
    for (int i = n - 1; i > 0; i--) {
      v[i] = f(v[i * 2 + 0], v[i * 2 + 1]);
    }
  }
  void update(int k, T x) {
    v[k += n] = x;
    while (k >>= 1) v[k] = f(v[k * 2 + 0], v[k * 2 + 1]);
  }
  T query(int a, int b) {
    T l = e, r = e;
    for (a += n, b += n; a < b; a >>= 1, b >>= 1) {
      if (a & 1) l = f(l, v[a++]);
      if (b & 1) r = f(v[--b], r);
    }
    return f(l, r);
  }
};

void solve() {
  int n, k, c;
  cin >> n >> k >> c;
  string s;
  cin >> s;
  SegmentTree<int> dp(n, [](int a, int b) { return max(a, b); }, 0);
  rep(i, n) {
    if (s[i] == 'x') continue;
    int v = dp.query(0, max(0, i - c)) + 1;
    if (v > k) {
      return;
    }
    dp.update(i, v);
  }
  SegmentTree<int> op(n, [](int a, int b) { return min(a, b); }, 1e9);
  vector<bool> en(n);
  rrep(i, n) {
    if (s[i] == 'x') continue;
    int x = dp.query(i, i + 1);
    if (x == k) {
      en[i] = true;
      op.update(i, x);
      continue;
    }
    if (op.query(min(n, i + c + 1), n) == x + 1) {
      en[i] = true;
      op.update(i, x);
    }
  }
  vector<set<int>> ve(k);
  rep(i, n) {
    if (en[i]) ve[dp.query(i, i + 1) - 1].insert(i + 1);
  }
  rep(i, k) {
    if (sz(ve[i]) == 1) {
      cout << (*ve[i].begin()) << endl;
    }
  }
}