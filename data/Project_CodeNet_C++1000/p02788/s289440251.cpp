#include <bits/stdc++.h>

// #undef DEBUG  // Uncomment this line to forcefully disable debug print.
#if DEBUG
template <typename T>
void debug(T value) {
  std::cerr << value;
}
template <typename T, typename... Ts>
void debug(T value, Ts... args) {
  std::cerr << value << ", ";
  debug(args...);
}
#define DBG(...)                              \
  do {                                        \
    cerr << #__VA_ARGS__ << ": ";             \
    debug(__VA_ARGS__);                       \
    cerr << " (L" << __LINE__ << ")" << endl; \
  } while (0)
#else
#define DBG(...)
#endif

void read_from_cin() {}
template <typename T, typename... Ts>
void read_from_cin(T& value, Ts&... args) {
  std::cin >> value;
  read_from_cin(args...);
}
#define CIN(type, ...) \
  type __VA_ARGS__;    \
  read_from_cin(__VA_ARGS__);

template <typename T>
void write_to_cout(const T& value) {
  std::cout << value << std::endl;
}
template <typename T, typename... Ts>
void write_to_cout(const T& value, const Ts&... args) {
  std::cout << value << ' ';
  write_to_cout(args...);
}
#define COUT(...) write_to_cout(__VA_ARGS__);

#define ALL(x) (x).begin(), (x).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;

using namespace std;

template <typename X, typename M>
    struct SegTreeLazyProportional {
  using FX = function<X(X, X)>;
  using FA = function<X(X, M)>;
  using FM = function<M(M, M)>;
  using FP = function<M(M, int)>;
  int n;
  FX fx;
  FA fa;
  FM fm;
  FP fp;
  const X ex;
  const M em;
  vector<X> dat;
  vector<M> lazy;
  SegTreeLazyProportional(int n_, FX fx_, FA fa_, FM fm_, FP fp_, X ex_, M em_)
      : n(), fx(fx_), fa(fa_), fm(fm_), fp(fp_), ex(ex_), em(em_), dat(n_ * 4, ex), lazy(n_ * 4, em) {
    int x = 1;
    while (n_ > x) x *= 2;
    n = x;
  }

  void set(int i, X x) { dat[i + n - 1] = x; }
  void build() {
    for (int k = n - 2; k >= 0; k--) dat[k] = fx(dat[2 * k + 1], dat[2 * k + 2]);
  }

  /* lazy eval */
  void eval(int k, int len) {
    if (lazy[k] == em) return;  // 更新するものが無ければ終了
    if (k < n - 1) {            // 葉でなければ子に伝搬
      lazy[k * 2 + 1] = fm(lazy[k * 2 + 1], lazy[k]);
      lazy[k * 2 + 2] = fm(lazy[k * 2 + 2], lazy[k]);
    }
    // 自身を更新
    dat[k] = fa(dat[k], fp(lazy[k], len));
    lazy[k] = em;
  }

  void update(int a, int b, M x, int k, int l, int r) {
    eval(k, r - l);
    if (a <= l && r <= b) {  // 完全に内側の時
      lazy[k] = fm(lazy[k], x);
      eval(k, r - l);
    } else if (a < r && l < b) {                     // 一部区間が被る時
      update(a, b, x, k * 2 + 1, l, (l + r) / 2);  // 左の子
      update(a, b, x, k * 2 + 2, (l + r) / 2, r);  // 右の子
      dat[k] = fx(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
  }
  void update(int a, int b, M x) { update(a, b, x, 0, 0, n); }

  X query_sub(int a, int b, int k, int l, int r) {
    eval(k, r - l);
    if (r <= a || b <= l) {  // 完全に外側の時
      return ex;
    } else if (a <= l && r <= b) {  // 完全に内側の時
      return dat[k];
    } else {  // 一部区間が被る時
      X vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
      X vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
      return fx(vl, vr);
    }
  }
  X query(int a, int b) { return query_sub(a, b, 0, 0, n); }
};

struct Monster {
  ll X, H;
  bool operator<(const Monster& m) const {
    return X < m.X;
  }
};

Monster monster[200000];

int main() {
  CIN(ll, N, D, A);
  REP(i, N) cin >> monster[i].X >> monster[i].H;
  sort(monster, monster + N);

  auto add = [](ll a, ll b) -> ll { return a + b; };
  auto mul = [](ll a, int size) -> ll { return a * size; };

  SegTreeLazyProportional<ll, ll> tree(N, add, add, add, mul, 0, 0);
  REP(i, N) tree.set(i, monster[i].H);

  ll ans = 0;
  int mi = 0;
  while (mi < N) {
    int h = tree.query(mi, mi + 1);
    if (h <= 0) {
      ++mi;
      continue;
    }
    Monster max_m = {monster[mi].X + D * 2, 0};
    int ub = upper_bound(monster, monster + N, max_m) - monster;
    ll cnt = (h + A - 1) / A;
    tree.update(mi, ub, -cnt * A);
    ans += cnt;
  }
  COUT(ans);
}
