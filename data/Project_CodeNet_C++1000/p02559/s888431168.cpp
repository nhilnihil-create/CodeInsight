#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
using ll = long long;
const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

class BIT {
  vector<long long> dat;
public:
  BIT(int n) : dat(n + 1, 0LL) {}
  void add(int i, long long x) {
    i++;
    while (i < (int)dat.size()) {
      dat[i] += x;
      i += i & -i;
    }
  }
  long long sum(int r) {
    long long res = 0;
    while (r > 0) {
      res += dat[r];
      r -= r & -r;
    }
    return res;
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  BIT bit(n);
  rep(i, n) {
    ll a;
    cin >> a;
    bit.add(i, a);
  }
  rep(_, q) {
    int que;
    cin >> que;
    if (que) {
      int l, r;
      cin >> l >> r;
      cout << bit.sum(r)-bit.sum(l) << '\n';
    } else {
      int p;
      ll x;
      cin >> p >> x;
      bit.add(p, x);
    }
  }
  return 0;
}