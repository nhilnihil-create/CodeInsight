#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <utility>
#include <cmath>
using namespace std;
using ll = long long;

template <typename T>
void print_vec(const vector<T> &v) {
  int n = v.size();
  for (int i = 0; i < n; ++i) {
    if (i > 0) cout << ' ';
    cout << v[i];
  }
  cout << '\n';
}

int main() {
  ll x, k, d;
  cin >> x >> k >> d;
  ll ax = labs(x), ad = labs(d);
  if (ad >= ax) {
    if (k % 2 == 0) {
      cout << ax << '\n';
    } else {
      cout << ad - ax << '\n';
    }
    return 0;
  }
  ll t = ax / ad;
  if (k <= t) {
    cout << ax - ad * k << '\n';
  } else {
    if (((k ^ t) & 1) == 0) {
      cout << ax - ad * t << '\n';
    } else {
      cout << labs(ax - ad * (t + 1)) << '\n';
    }
  }

  return 0;
}
