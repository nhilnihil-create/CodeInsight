#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

using Pair = pair<int, int>;
using lint = long long;

// const int mod = 1e9 + 7;
// const int mod = 998244353;

template <typename T>
vector<T> make_v(size_t a) {
  return vector<T>(a);
}

template <typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
  return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}

int main() {
  int n, ret = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i % 2 == 0 && a[i] % 2 == 1) ret++;
  }

  cout << ret << endl;
}