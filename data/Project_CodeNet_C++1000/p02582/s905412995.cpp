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

  string s;
  cin >> s;
  int r = 0;
  for (int i = 0; i < 3; ++i) {
    if (s[i] == 'R') {
      ++r;
    }
  }
  if (r == 2 && s[1] == 'S') {
    r = 1;
  }
  cout << r << '\n';
  return 0;
}
