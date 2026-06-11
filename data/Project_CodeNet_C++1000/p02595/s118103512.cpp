#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <utility>
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
  int n;
  ll d;
  cin >> n >> d;
  ll x, y;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    if (x * x + y * y <= d * d) {
      ++cnt;
    }
  }
  cout << cnt << '\n';

  return 0;
}
