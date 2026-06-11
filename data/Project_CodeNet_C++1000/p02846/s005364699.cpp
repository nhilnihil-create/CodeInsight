#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
#define rrep(i, a, n) for (int i = (int)(a); i >= (int)(n); --i)
#define debug(x) cerr << #x << " = " << x << "\n"
#define debugv(x) \
  rep(f, 0, (x.size() - 1)) cerr << x[f] << (f == (x.size() - 1) ? "\n" : " ")
#define debug2(x, y)                       \
  cerr << "(" << #x << "," << #y << ") = " \
       << "(" << x << "," << y << ")\n"
#define all(x) x.begin(), x.end()
#define each(a, x) for (auto& a : (x))
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define int long long
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MX = 1e5 + 5, INF = 5LL << 57, MOD = 1e9 + 7;

int N, M;
string S;
vi va, vb;

int t1, t2, a1, a2, b1, b2;
void input() {
  cin >> t1 >> t2;
  cin >> a1 >> a2;
  cin >> b1 >> b2;
  ;
  ;
}
void solve() {
  int p = (a1 - b1) * t1;
  int q = (a2 - b2) * t2;

  if (p > 0) {
    p *= -1;
    q *= -1;
  }

  if (p + q < 0) {
    cout << 0 << endl;
  } else if (p + q == 0) {
    cout << "infinity" << endl;
  } else {
    int s = -p / (p + q);
    int t = (-p) % (p + q);
    if (t != 0) {
      cout << (s * 2 + 1) << endl;
    } else {
      cout << (s * 2) << endl;
    }
  };
  ;
}
signed main() {
  input();
  solve();
  return 0;
}