// clang-format off
#include <bits/stdc++.h>
#define int long long
#define main signed main()
// #define main int main()
#define loop(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) loop(i, 0, n)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prec(n) fixed << setprecision(n)
#define stlice(from, to) substr(from, (to) - (from) + 1)
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using vd = vector<double>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vpii = vector<pii>;
using vvi = vector<vi>;
using vvb = vector<vb>;
using vvpii = vector<vpii>;
template<typename A> using fn = function<A>;
constexpr int INF = sizeof(int) == sizeof(long long) ? 1000000000000000000LL : 1000000000;
constexpr int MOD = 1000000007;
constexpr double PI = acos(-1);
template<typename A, typename B> bool cmin(A &a, const B &b) { return a > b ? (a = b, true) : false; }
template<typename A, typename B> bool cmax(A &a, const B &b) { return a < b ? (a = b, true) : false; }
constexpr bool odd(const int &n) { return n & 1; }
constexpr bool even(const int &n) { return !odd(n); }
void solve();
main { solve(); return 0; }
// clang-format on

int erase(vvi &m) {
  int score = 0;
  rep(i, m.size()) {
    vi &ln = m[i];
    rep(j, 3) {
      if (ln[j] == 0) continue;
      if (ln[j] != ln[j + 1] || ln[j + 1] != ln[j + 2]) continue;
      if (j >= 2 || ln[j + 2] != ln[j + 3]) {
        score += ln[j] * 3;
        loop(k, j, j + 3) ln[k] = 0;
        break;
      }
      if (j >= 1 || ln[j + 3] != ln[j + 4]) {
        score += ln[j] * 4;
        loop(k, j, j + 4) ln[k] = 0;
        break;
      }
      score += ln[j] * 5;
      loop(k, j, j + 5) ln[k] = 0;
      break;
    }
  }
  return score;
}

void fall(vvi &m) {
  for (;;) {
    bool updated = false;
    for (int i = m.size() - 1; i > 0; i--) {
      rep(j, 5) if (m[i][j] == 0) {
        if (m[i - 1][j] != 0) {
          updated = true;
          for (int k = i; k > 0; k--) m[k][j] = m[k - 1][j];
          m[0][j]                             = 0;
        }
      }
    }
    if (!updated) break;
  }
}

void solve() {
  int h;
  while (cin >> h, h) {
    vvi m(h, vi(5));
    rep(i, h) rep(j, 5) cin >> m[i][j];
    int score = 0;
    for (;;) {
      bool updated             = false;
      int erased               = erase(m);
      if (erased != 0) updated = true;
      score += erased;
      fall(m);
      if (!updated) break;
    }
    cout << score << endl;
  }
}