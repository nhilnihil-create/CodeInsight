#include <bits/stdc++.h>
using namespace std;

template<typename T> struct SegTree {
  int sz;
  T init;
  function<T(T, T)> f;
  vector<T> data;
  SegTree() {}
  SegTree(int n, T init = INT_MAX, function<T(T, T)> f = [](T a, T b) { return min(a, b); })
    : data(set_data(n), init), init(init), f(f) {}

  int set_data(int n) {
    sz = 1;
    while (sz < n) sz <<= 1;
    return 2 * sz - 1;
  }
  void update(int k, T x) {
    k += sz - 1;
    data[k] = f(data[k], x);
    while (k > 0) {
      k = (k - 1) / 2;
      data[k] = f(data[k * 2 + 1], data[k * 2 + 2]);
    }
  }
  T query(int s, int t) { return query(s, t, 0, 0, sz); }
  T query(int s, int t, int k, int l, int r) {
    if (r <= s || t <= l) return init;
    if (s <= l && r <= t) return data[k];
    int m = (l + r) / 2;
    T vl = query(s, t, k * 2 + 1, l, m);
    T vr = query(s, t, k * 2 + 2, m, r);
    return f(vl, vr);
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, q; cin >> n >> q;
  SegTree<int> st(n, 0, [](int a, int b) { return a + b; });
  for (int i = 0; i < q; ++i) {
    int com, x, y; cin >> com >> x >> y;
    if (com) {
      cout << st.query(x - 1, y) << endl;
    } else {
      st.update(x - 1, y);
    }
  }
  return 0;
}

