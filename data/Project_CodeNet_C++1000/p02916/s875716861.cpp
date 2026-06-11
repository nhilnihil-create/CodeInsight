#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int n; cin >> n;
  vector <int> a(n);
  vector <int> b(n);
  vector <int> c(n-1);
  int res = 0;
  for (auto &m: a) {
    cin >> m;
  }
  for (auto &m: b) {
    cin >> m;
    res += m;
  }
  for (auto &m: c) {
    cin >> m;
  }
  for (int i = 0; i < a.size()-1; i++ ) {
    if (a[i] + 1 == a[i+1]) {
      res += c[a[i]-1];
    }
  }
  cout << res;
}