#include <bits/stdc++.h>
using namespace std;
template< typename T >
struct segment_tree {
  int sz;
  vector<T> seg;
  const function<T(T, T)> o;
  const T id;
  segment_tree(int n, const function<T(T, T)> o, const T &id)
    : o(o)
    , id(id)
  {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz, id);
  }
  void add(int k, const T &x) {
    k += sz;
    seg[k] += x;
    while(k >>= 1) {
      seg[k] = o(seg[2 * k], seg[2 * k + 1]);
    }
  }
  T find(int a, int b) {
    T L = id, R = id;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) L = o(L, seg[a++]);
      if(b & 1) R = o(seg[--b], R);
    }
    return o(L, R);
  }
  T operator[](const int &k) const {
    return seg[k + sz];
  }
  void print() {
    cout << "segment_tree:" << endl;
    int crr = 1;
    for (int p = sz; p; p >>= 1) {
      for (int i = 0; i < sz; i++) {
        cout
            << setw(12)
            << (i % p == 0 ? to_string(seg[crr++]) : "")
            << (i < sz - 1 ? "" : "\n");
      }
    }
    cout << endl;
  }
};
int main() {
  int n, q;
  cin >> n >> q;
  segment_tree<int> sgt(n, [](int a, int b) {return a + b;}, 0);
  while (q--) {
    int c, x, y;
    cin >> c >> x >> y;
    if (c) cout << sgt.find(x, y + 1) << endl;
    else sgt.add(x, y);
  }
  return 0;
}
