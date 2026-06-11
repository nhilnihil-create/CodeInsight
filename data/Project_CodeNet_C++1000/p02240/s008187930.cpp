// clang-format off
#include <bits/stdc++.h>
#define int long long
#define main signed main()
#define loop(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) loop(i, 0, n)
#define forever while (true)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prec(n) fixed << setprecision(n)
template<typename A> using V = std::vector<A>;
template<typename A> using F = std::function<A>;
template<typename A, typename B> using P = std::pair<A, B>;
using pii = P<int, int>;
using vi = V<int>;
using vd = V<double>;
using vs = V<std::string>;
using vpii = V<pii>;
using vvi = V<vi>;
using vvpii = V<vpii>;
constexpr int INF = sizeof(int) == sizeof(long long) ? 1000000000000000000LL : 1000000000;
constexpr int MOD = 1000000007;
constexpr double PI = acos(-1);
template<typename A, typename B> bool cmin(A &a, const B &b) { return a > b ? (a = b, true) : false; }
template<typename A, typename B> bool cmax(A &a, const B &b) { return a < b ? (a = b, true) : false; }
template<typename T> std::istream &operator>>(std::istream &is, std::vector<T> &v) { for (T &x : v) is >> x; return is; }
using namespace std;
// clang-format on

class UFTree {
  std::vector<int> data, rank, _size;

public:
  UFTree(const int &n) : data(n), rank(n), _size(n, 1) { iota(all(data), 0); }

  int root(const int &x) { return data[x] == x ? x : data[x] = root(data[x]); }

  bool same(const int &a, const int &b) { return root(a) == root(b); }

  void unite(int a, int b) {
    a = root(a), b = root(b);
    if (a == b) return;
    if (rank[a] < rank[b]) std::swap(a, b);
    data[b] = a;
    _size[a] += _size[b];
    if (rank[a] == rank[b]) rank[a]++;
  }

  int sizeOf(int x) { return _size[root(x)]; }
};

main {
  int n, m;
  cin >> n >> m;
  UFTree uf(n);
  while (m--) {
    int s, t;
    cin >> s >> t;
    uf.unite(s, t);
  }
  int q;
  cin >> q;
  while (q--) {
    int s, t;
    cin >> s >> t;
    cout << (uf.same(s, t) ? "yes" : "no") << endl;
  }
}