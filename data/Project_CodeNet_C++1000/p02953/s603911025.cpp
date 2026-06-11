#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)

int main() {
  int n;
  cin >> n;
  vector<ll> h(n);
  rep(i, 0, n) cin >> h[i];
  reverse(h.begin(), h.end());
  rep(i, 0, n - 1) {
    if (h[i] < h[i + 1]) {
      --h[i + 1];
      if (h[i] < h[i + 1]) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;

  return 0;
}
