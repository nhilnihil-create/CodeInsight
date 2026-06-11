// clang-format off
#include <bits/stdc++.h>
#define int long long
#define main signed main()
#define loop(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) loop(i, 0, n)
#define forever while(true)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prec(n) fixed << setprecision(n)
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
using pii   = std::pair<int, int>;
using vi    = std::vector<int>;
using vd    = std::vector<double>;
using vc    = std::vector<char>;
using vb    = std::vector<bool>;
using vs    = std::vector<std::string>;
using vpii  = std::vector<pii>;
using vvi   = std::vector<vi>;
using vvb   = std::vector<vb>;
using vvpii = std::vector<vpii>;
template<typename A> using fn = std::function<A>;
constexpr int INF   = sizeof(int) == sizeof(long long) ? 1000000000000000000LL : 1000000000;
constexpr int MOD   = 1000000007;
constexpr double PI = acos(-1);
template<typename A, typename B> bool cmin(A &a, const B &b) { return a > b ? (a = b, true) : false; }
template<typename A, typename B> bool cmax(A &a, const B &b) { return a < b ? (a = b, true) : false; }
using namespace std;
// clang-format on

template<typename T>
struct Monoid {
  T id;
  std::function<T(T, T)> op;
  Monoid(T e, std::function<T(T, T)> f)
    : id(e), op(f) {
  }
};

template<typename T>
class SegTree {
private:
  vector<T> data;
  Monoid<T> monoid;
  int size = 1;

public:
  SegTree(const int &n, const Monoid<T> &m)
    : monoid(m) {
    while (size < n) size *= 2;
    data = vector<T>(2 * size, monoid.id);
  }

  void update(int i, const T &x) {
    i += size;
    data[i]                = x;
    while (i /= 2) data[i] = monoid.op(data[i * 2], data[i * 2 + 1]);
  }

  // fold [a, b) by monoid.op
  T fold(const int &a, const int &b, const int &k = 1, const int &l = 0, int r = -1) {
    if (r == -1) r = size;
    if (r <= a || b <= l) return monoid.id;
    if (a <= l && r <= b) return data[k];
    return monoid.op(fold(a, b, k * 2, l, (l + r) / 2),
                     fold(a, b, k * 2 + 1, (l + r) / 2, r));
  }

  const T &operator[](const int &i) const {
    return data[i + size];
  }
};

Monoid<int> sumMonoid = {0, plus<int>()};

main {
  int n, q;
  cin >> n >> q;
  SegTree<int> t(n, sumMonoid);
  while (q--) {
    int com, x, y;
    cin >> com >> x >> y;
    x--;
    if (com) {
      cout << t.fold(x, y) << endl;
    } else {
      t.update(x, t[x] + y);
    }
  }
}