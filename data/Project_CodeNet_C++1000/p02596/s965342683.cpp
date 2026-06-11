#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <utility>
#include <unordered_set>

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
  int k;
  cin >> k;
  int prev = 0;
  vector<bool> exist(k, false);
  int t = 1;
  int ans = -1;
  for (;;) {
    prev = prev * 10 + 7;
    if (prev % k == 0) {
      ans = t;
      break;
    }
    prev %= k;
    if (exist[prev]) {
      break;
    } else {
      exist[prev] = true;
    }
    ++t;
  }
  cout << ans << '\n';

  return 0;
}
