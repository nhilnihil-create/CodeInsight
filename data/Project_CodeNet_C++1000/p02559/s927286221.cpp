#include <bits/stdc++.h>
using namespace std;

#pragma region lib_fenwick_tree
namespace lib {
  /*
    class FenwickTree
    usage: Fenwicktree f(100), FenwickTree<long long> f(100)
  */
  template <class T = int> class FenwickTree {
    public:
    FenwickTree() {}
    FenwickTree(int s) :
        size(s), data(s + 1, (T) 0) {}
    FenwickTree(const vector<T> &d) {
      size = d.size();
      data = vector<T>(size + 1, (T) 0);
      for (int i = 0; i < size; i++) add(i, d[i]);
    }

    /* index value must be 0-indexed */
    void add(int idx, const T &diff) {
      for (idx++; idx <= size; idx += (idx & -idx)) {
        data[idx] += diff;
      }
    }

    /* sum of the interval [0, idx] (inclusive, 0-indexed) */
    T sum(int idx) {
      T ret = 0;
      for (idx++; idx > 0; idx -= (idx & -idx)) {
        ret += data[idx];
      }
      return ret;
    }

    /* sum of the interval [l, r] (inclusive, 0-indexed) */
    T rangeSum(int l, int r) {
      return sum(r) - sum(l - 1);
    }

    private:
    int size;
    vector<T> data;
  };
}  // namespace lib
#pragma endregion

int main() {
  int N, Q;
  cin >> N >> Q;
  
  vector<long long> a(N);
  for (long long &in : a) cin >> in;
  
  lib::FenwickTree<long long> f(a);
  
  while (Q--) {
    int x, y, z;
    cin >> x >> y >> z;
    if (x == 0)
      f.add(y, z);
    else
      cout << f.rangeSum(y, z - 1) << endl;
  }
  
  return 0;
}
