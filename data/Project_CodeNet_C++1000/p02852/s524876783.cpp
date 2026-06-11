#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
#ifdef __LOCAL
#define debug(x) cerr << __LINE__ << ": " << #x << " = " << x << endl
#define debugArray(x, n)                           \
  cerr << __LINE__ << ": " << #x << " = {";        \
  for (long long hoge = 0; (hoge) < (n); ++(hoge)) \
    cerr << ((hoge) ? "," : "") << x[hoge];        \
  cerr << "}" << endl
#else
#define debug(x) (void(0))
#define debugArray(x, n) (void(0))
#endif

template <typename M>
struct SegmentTree {
  using T = typename M::T;

 private:
  const int n;
  vector<T> dat;

 private:
  template <typename C>
  int find_subtree(int a, const C &check, T &cur, bool type) {
    while (a < n) {
      T nxt
          = type ? M::f(dat[2 * a + type], cur) : M::f(cur, dat[2 * a + type]);
      if (check(nxt))
        a = 2 * a + type;
      else
        cur = nxt, a = 2 * a + !type;
    }
    return a - n;
  }

 public:
  SegmentTree() {}
  SegmentTree(int n_, T v1 = M::ti()) : SegmentTree(vector<T>(n_, v1)) {}
  SegmentTree(const vector<T> &v)
      : n(1 << int(ceil(log2(v.size())))), dat(n << 1, M::ti()) {
    for (int i = 0; i < (int)v.size(); i++) dat[i + n] = v[i];
    for (int i = n - 1; i >= 1; i--)
      dat[i] = M::f(dat[i << 1 | 0], dat[i << 1 | 1]);
  }
  void set_val(int k, T x) {
    for (dat[k += n] = x; k >>= 1;)
      dat[k] = M::f(dat[(k << 1) | 0], dat[(k << 1) | 1]);
  }
  //[a,b)
  T query(int a, int b) {
    T vl = M::ti(), vr = M::ti();
    for (int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) vl = M::f(vl, dat[l++]);
      if (r & 1) vr = M::f(dat[--r], vr);
    }
    return M::f(vl, vr);
  }
  T operator[](const int &k) const { return dat[k + n]; }
  // min { i : check(query(a,i+1)) = true }
  template <typename C>
  int find_first(const C &check, int a = 0) {
    T vl = M::ti();
    if (a <= 0) {
      if (check(M::f(vl, dat[1]))) return find_subtree(1, check, vl, false);
      return -1;
    }
    int b = n;
    for (a += n, b += n; a < b; a >>= 1, b >>= 1)
      if (a & 1) {
        T nxt = M::f(vl, dat[a]);
        if (check(nxt)) return find_subtree(a, check, vl, false);
        vl = nxt;
        ++a;
      }
    return -1;
  }
  // max { i : check(query(i,b)) = true }
  template <typename C>
  int find_last(const C &check, int b = -1) {
    if (b < 0) b = n;
    T vr = M::ti();
    if (b >= n) {
      if (check(M::f(dat[1], vr))) return find_subtree(1, check, vr, true);
      return -1;
    }
    int a = 0;
    for (a += n, b += n; a < b; a >>= 1, b >>= 1)
      if (b & 1) {
        T nxt = M::f(dat[--b], vr);
        if (check(nxt)) return find_subtree(b, check, vr, true);
        vr = nxt;
      }
    return -1;
  }
};

struct Mono {
  using T = pair<int, int>;
  static T ti() { return make_pair(INT_MAX, INT_MAX); }
  static T f(const T &vl, const T &vr) { return vl.first > vr.first ? vr : vl; }
};

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;
  string S;
  cin >> S;
  const int INF = INT_MAX / 10;
  SegmentTree<Mono> seg(N + 1);
  seg.set_val(N, make_pair(0, N));
  bool isok = true;
  for (int i = N - 1; i >= 0; i--) {
    if (S[i] == '1') {
      seg.set_val(i, make_pair(INF, i));
      continue;
    }
    int R = min(N + 1, i + M + 1);
    int a = seg.query(i + 1, R).first;
    if (a == INF) {
      isok = false;
      break;
    }
    seg.set_val(i, make_pair(a + 1, i));
  }
  if (!isok) {
    cout << -1 << '\n';
    return 0;
  }
  vector<int> ans;
  int cur = 0;
  while (cur < N) {
    int R = min(N + 1, cur + M + 1);
    auto tmp = seg.query(cur + 1, R);
    ans.push_back(tmp.second - cur);
    cur = tmp.second;
  }
  for (int i = 0; i < (int)ans.size(); i++) cout << (i ? " " : "") << ans[i];
  cout << '\n';
  return 0;
}
