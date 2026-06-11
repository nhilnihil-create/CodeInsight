#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)
#define rrep(i, j, n) for (int i = (int)n - 1; j <= i; --i)

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (ll& x : a) cin >> x;

  ll kane = 1000;
  ll kabu = 0;
  rep(i, 0, n - 1) {
    if (a[i] < a[i + 1]) {
      kabu += kane / a[i];
      kane = kane % a[i];
    }
    if (a[i] > a[i + 1]) {
      kane += kabu * a[i];
      kabu = 0;
    }
  }
  kane += kabu * a[n - 1];
  cout << kane << endl;
  return 0;
}
