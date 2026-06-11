#include <limits.h>

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
using namespace std;
using P = pair<int, int>;
using ll = long long;
template <typename T = long long>
vector<T> make_v(size_t a) {
  return vector<T>(a);
}
template <typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
  return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int k;
  cin >> k;
  rep(i, k + 1) {
    rep(j, k - i + 1) {
      int aa = a * pow(2, i), bb = b * pow(2, j), cc = c * pow(2, k - i - j);
      if (aa < bb && bb < cc) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}
