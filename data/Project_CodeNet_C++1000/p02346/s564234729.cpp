// clang-format off
#include <bits/stdc++.h>
#define int long long
#define main signed main()
#define loop(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) loop(i, 0, n)
#define forever for (;;)
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
template<typename A, typename B> std::istream &operator>>(std::istream &is, std::pair<A, B> &p) { is >> p.first; is >> p.second; return is; }
using namespace std;
// clang-format on

template<typename Group> class FenwickTree {
  using T = typename Group::value_type;

  Group g;
  std::vector<T> tree; // 1-indexed
  int size;

public:
  FenwickTree(const int &n = 0) : size(n), g() { tree.assign(size + 1, g.id()); }

  T fold(int i) { // [0, i)
    T acc = g.id();
    for (; i; i -= i & -i) acc = g(acc, tree[i]);
    return acc;
  }

  T fold(const int &l, const int &r) { return g(fold(r), g.inv(fold(l))); } // [l, r)

  void add(int i, const T &x) {
    for (i++; i <= size; i += i & -i) tree[i] = g(tree[i], x);
  }

  void update(int i, const T &a) { add(i + 1, a - fold(i + 1, i + 2)); }
};

template<typename T> struct sumGroup {
  using value_type = T;
  constexpr T id() const { return 0; }
  T operator()(const T &a, const T &b) const { return a + b; }
  T inv(const T &x) const { return -x; }
};

main {
  int n, q;
  cin >> n >> q;
  FenwickTree<sumGroup<int>> t(n);
  while (q--) {
    int com, x, y;
    cin >> com >> x >> y;
    x--;
    if (com) {
      cout << t.fold(x, y) << endl;
    } else {
      t.add(x, y);
    }
  }
}