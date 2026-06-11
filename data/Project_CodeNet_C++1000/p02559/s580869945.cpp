#include <bits/stdc++.h>
using namespace std;

// 0-indexed
template <class T>
struct BIT {
  int treesize;
  vector<T> lst;
  // constructor
  BIT(int newn = 0) : treesize(newn), lst(newn + 1, 0) {}
  // a_place += num
  void add(int place, T num) {
    ++place;
    while (place <= treesize) {
      lst[place] += num;
      place += place & -place;
    }
  }
  // sum between [0,place)
  T sum(int place) {
    T res = 0;
    while (place > 0) {
      res += lst[place];
      place -= place & -place;
    }
    return res;
  }
  // sum [l,r)
  T sum(int left, int right) { return sum(right) - sum(left); }
};

int main() {
  int n, q;
  cin >> n >> q;
  BIT<long long> bit(n);
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    bit.add(i, a);
  }
  while (q--) {
    int t, u, v;
    cin >> t >> u >> v;
    if (t)
      cout << bit.sum(u, v) << endl;
    else
      bit.add(u, v);
  }

  return 0;
}