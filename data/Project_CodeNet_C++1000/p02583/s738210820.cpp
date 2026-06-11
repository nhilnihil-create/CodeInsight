#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <utility>
using namespace std;

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
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &ai: a) cin >> ai;
  sort(a.begin(), a.end());
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (a[j] == a[i]) continue;
      for (int k = j + 1; k < n; ++k) {
        if (a[k] == a[i] || a[k] == a[j]) continue;
        if (a[i] + a[j] > a[k]) {
          ++ans;
        }
      }
    }
  }
  cout << ans << '\n';

  return 0;
}
