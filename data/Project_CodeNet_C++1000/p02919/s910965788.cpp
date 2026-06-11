#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

typedef pair<ll, ll> P;

#define all(v) v.begin(), v.end()

#define rep(i, n) for (ll i = 0; i < n; i++)
#define REP(i, n) for (ll i = 1; i < n; i++)

template <class T>
inline void chmax(T& a, T b) {
  a = std::max(a, b);
}
template <class T>
inline void chmin(T& a, T b) {
  a = std::min(a, b);
}

#define mod (ll)(1e9 + 7)
#define INF LLONG_MAX

template <typename T>
class SegTree {
  int n;
  vector<T> data;
  T initial_value;
  function<T(T a, T b)> operation;
  function<T(T prev_val, T new_val)> _update;

  // [a,b)
  T query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) {
      return initial_value;
    }

    if (a <= l && r <= b) {
      return data[k];
    } else {
      T vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
      T vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
      return operation(vl, vr);
    }
  }

 public:
  SegTree(size_t _n, T _initial_value, function<T(T a, T b)> _operation,
          function<T(T prev_val, T new_val)> update_function)
    : initial_value(_initial_value), operation(_operation), _update(update_function) {
    n = 1;
    while (n < _n) {
      n <<= 1;
    }
    data = vector<T>(2 * n - 1, initial_value);
  }

  // update i-th value (0-indexed)
  void update(int i, T x) {
    i += n - 1;
    data[i] = _update(data[i], x);
    while (i > 0) {
      i = (i - 1) / 2;
      data[i] = operation(data[i * 2 + 1], data[i * 2 + 2]);
    }
  }

  // execute query of section [a, b)
  T query(int a, int b) {
    return query(a, b, 0, 0, n);
  }

  // get i-th value
  T operator[](int i) {
    return data[i + n - 1];
  }
};

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);

  ll n;
  cin >> n;

  vll p(n + 2, mod);
  REP(i, n + 1) {
    cin >> p[i];
  }

  // get max
  SegTree<ll> st(
    n + 2, 0ll, [&](ll a, ll b) { return max(a, b); }, [&](ll prev_val, ll new_val) { return new_val; });

  rep(i, n + 2) {
    st.update(i, p[i]);
  }

  vll ll1(n + 2, 0);
  vll lr1(n + 2, n + 1);

  REP(i, n + 1) {
    int l = i + 1, r = n + 1;
    while (l < r) {
      int c = (l + r) / 2;
      ll max_val = st.query(i, c + 1);
      if (max_val != p[i]) {
        r = c;
      } else {
        l = c + 1;
      }
    }
    lr1[i] = l;

    l = 0;
    r = i - 1;
    while (l < r) {
      int c = (l + r + 1) / 2;
      ll max_val = st.query(c, i + 1);
      if (max_val != p[i]) {
        l = c;
      } else {
        r = c - 1;
      }
    }
    ll1[i] = l;
  }
  ll1[0] = 0;
  lr1[n + 1] = n + 1;

  vll ll2(n + 2, 0);
  vll lr2(n + 2, n + 1);

  REP(i, n + 1) {
    int l = min(n + 1, lr1[i] + 1);
    int r = n + 1;
    while (l < r) {
      int c = (l + r) / 2;
      ll max_val = st.query(lr1[i] + 1, c + 1);
      if (max_val > p[i]) {
        r = c;
      } else {
        l = c + 1;
      }
    }
    lr2[i] = l;

    l = 0;
    r = max(0ll, ll1[i] - 1);
    while (l < r) {
      int c = (l + r + 1) / 2;
      ll max_val = st.query(c, ll1[i]);
      if (max_val > p[i]) {
        l = c;
      } else {
        r = c - 1;
      }
    }
    ll2[i] = l;
  }
  ll2[0] = 0;
  lr2[n + 1] = n + 1;

  ll ans = 0;
  REP(i, n + 1) {
    ll cnt = 0;
    ll la = ll2[i] + 1;
    ll ra = ll1[i];
    ll lb = i;
    ll rb = lr1[i] - 1;

    cnt += (ra - la + 1) * (rb - lb + 1);

    la = ll1[i] + 1;
    ra = i;
    lb = lr1[i];
    rb = lr2[i] - 1;
    cnt += (ra - la + 1) * (rb - lb + 1);

    ans += p[i] * cnt;
  }

  cout << ans << endl;

  return 0;
}
