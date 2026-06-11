#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < int(n); i++)
#define rrep(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define reps(i, n) for (int i = 1; i <= int(n); i++)
#define rreps(i, n) for (int i = int(n); i >= 1; i--)
#define repc(i, n) for (int i = 0; i <= int(n); i++)
#define rrepc(i, n) for (int i = int(n); i >= 0; i--)
#define repi(i, a, b) for (int i = int(a); i < int(b); i++)
#define repic(i, a, b) for (int i = int(a); i <= int(b); i++)
#define repp(i, n) rep(i, n)
#define reppp(i, n) repp(i, n)
#define rrepp(i, n) rrep(i, n)
#define repss(i, n) reps(i, n)
#define repcc(i, n) repc(i, n)
#define repii(i, a, b) repi(i, a, b)
#define each(x, y) for (auto &x : y)
#define all(a) (a).begin(), (a).end()
#define bit(b) (1ll << (b))

using namespace std;

using i32 = int;
using i64 = long long;
using u64 = unsigned long long;
using f80 = long double;
using vi32 = vector<i32>;
using vi64 = vector<i64>;
using vu64 = vector<u64>;
using vf80 = vector<f80>;
using vstr = vector<string>;

inline void yes() { cout << "Yes" << '\n'; exit(0); }
inline void no() { cout << "No" << '\n'; exit(0); }
inline i64 gcd(i64 a, i64 b) { if (min(a, b) == 0) return max(a, b); if (a % b == 0) return b; return gcd(b, a % b); }
inline i64 lcm(i64 a, i64 b) { return a / gcd(a, b) * b; }
inline u64 xorshift() { static u64 x = 88172645463325252ull; x = x ^ (x << 7); return x = x ^ (x >> 9); }
void solve(); int main() { ios::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(16); solve(); return 0; }
template <typename T> class pqasc : public priority_queue<T, vector<T>, greater<T>> {};
template <typename T> class pqdesc : public priority_queue<T, vector<T>, less<T>> {};
template <typename T> inline void amax(T &x, T y) { if (x < y) x = y; }
template <typename T> inline void amin(T &x, T y) { if (x > y) x = y; }
template <typename T> inline T power(T x, i64 n, T e = 1) { T r = e; while (n > 0) { if (n & 1) r *= x; x *= x; n >>= 1; } return r; }
template <typename T> istream& operator>>(istream &is, vector<T> &v) { each(x, v) is >> x; return is; }
template <typename T> ostream& operator<<(ostream &os, vector<T> &v) { rep(i, v.size()) { if (i) os << ' '; os << v[i]; } return os; }
template <typename T, typename S> istream& operator>>(istream &is, pair<T, S> &p) { is >> p.first >> p.second; return is; }
template <typename T, typename S> ostream& operator<<(ostream &os, pair<T, S> &p) { os << p.first << ' ' << p.second; return os; }

int numofbits5(long bits) {
  bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
  bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
  bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
  bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
  return (bits & 0x0000ffff) + (bits >>16 & 0x0000ffff);
}

void solve() {
  int N; cin >> N;
  if (numofbits5(N) == 1) no();

  // cerr << (65536 ^ 5 ^ 1) << '\n';
  // return;

  cout << "Yes" << '\n';
  
  vector<pair<int, int>> ans;
  
  ans.emplace_back(0, 1);
  ans.emplace_back(1, 2);
  ans.emplace_back(2, N);
  ans.emplace_back(N, N + 1);
  ans.emplace_back(N + 1, N + 2);

  for (int i = 3; i <= N - 2; i += 2) {
    ans.emplace_back(N, i);
    ans.emplace_back(i, i + 1);
    ans.emplace_back(N, N + i + 1);
    ans.emplace_back(N + i + 1, N + i);
  }

  if (N % 2 == 0) {
    int k = 0, n = N;
    while (n) n >>= 1, k++;
    int v = bit(k - 1);
    int u = N ^ v;
    if (u + 1 == 3) {
      ans.emplace_back(v - 1, N - 1);
      ans.emplace_back(u, N * 2 - 1);
    } else {
      ans.emplace_back(v - 1, N - 1);
      ans.emplace_back(u + N, N * 2 - 1);
    }
  }

  rep(i, ans.size()) {
    cout << ans[i].first + 1 << " " << ans[i].second + 1 << '\n';
  }
}
