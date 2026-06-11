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
  string s;
  cin >> n >> s;
  int i = 0, j = n - 1;
  int cnt = 0;
  while (i < j) {
    while (i < n && s[i] == 'R') ++i;
    while (j >= 0 && s[j] == 'W') --j;
    if (i == n) break;
    if (j < 0) break;
    if (i < j) {
      ++i; --j; ++cnt;
    }
  }

  cout << cnt << '\n';

  return 0;
}
