#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, r;
  while (cin >> n >> r, n || r) {
    vector<int> a;
    a.reserve(n);
    for (int i = 0; i < n; ++i) {
      a.emplace_back(n - i);
    }
    for (int i = 0; i < r; ++i) {
      int p, c;
      cin >> p >> c;
      vector<int> b;
      b.reserve(n);
      for (int j = p - 1; j < p - 1 + c; ++j) {
        b.emplace_back(a[j]);
      }
      for (int j = 0; j < n; ++j) {
        if (p - 1 <= j && j < p - 1 + c) continue;
        b.emplace_back(a[j]);
      }
      a = b;
    }
    cout << a[0] << endl;
  }
}