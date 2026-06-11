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

inline void yes() { cout << "Yes" << endl; exit(0); }
inline void no() { cout << "No" << endl; exit(0); }
inline i64 gcd(i64 a, i64 b) { if (min(a, b) == 0) return max(a, b); if (a % b == 0) return b; return gcd(b, a % b); }
inline i64 lcm(i64 a, i64 b) { if (min(a, b) == 0) return max(a, b); return a / gcd(a, b) * b; }
template <typename T> class pqasc : public priority_queue<T, vector<T>, greater<T>> {};
template <typename T> class pqdesc : public priority_queue<T, vector<T>, less<T>> {};
template <typename T> inline void amax(T &x, T y) { x = max(x, y); }
template <typename T> inline void amin(T &x, T y) { x = min(x, y); }
template <typename T> inline T exp(T x, i64 n, T e = 1) { T r = e; while (n > 0) { if (n & 1) r *= x; x *= x; n >>= 1; } return r; }
template <typename T> istream& operator>>(istream &is, vector<T> &v) { for (auto &x : v) is >> x; return is; }
template <typename T> ostream& operator<<(ostream &os, vector<T> &v) { rep(i, v.size()) { if (i) os << ' '; os << v[i]; } return os; }
void solve(); int main() { ios::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(16); solve(); return 0; }

void solve() {
  int n;
  cin >> n;
  using P = pair<f80, f80>;
  vi32 x(n), y(n);
  vector<P> target;
  rep(i, n) {
    cin >> x[i] >> y[i];
    target.emplace_back(-y[i], x[i]);
    target.emplace_back(-y[i], x[i] + 0.0001);
    target.emplace_back(-y[i], x[i] - 0.0001);
    target.emplace_back(y[i], -x[i]);
    target.emplace_back(y[i], -x[i] + 0.0001);
    target.emplace_back(y[i], -x[i] - 0.0001);
  }
  f80 ans = 0;
  rep(i, sz(target)) {
    f80 nx, ny;
    tie(nx, ny) = target[i];
    int fx = 0, fy = 0;
    rep(j, n) {
      if (nx * x[j] + ny * y[j] >= 0) {
        fx += x[j], fy += y[j];
      }
    }
    f80 sum = sqrt(pow((f80) fx, 2) + pow((f80) fy, 2));
    amax(ans, sum);
  }
  cout << ans << endl;
}
