#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------

using ld = long double;
ld a, b, x;

int main() {
  cin >> a >> b >> x;
  if (x < a * a * b / 2.0) {
    ld c = 2.0 * x / (a * b);
    ld rad = atan(b / c);
    cout << setprecision(20) << fixed << rad * 180.0 / M_PI;
  } else {
    x = (a * a * b) - x;
    ld c = 2.0 * x / (a * a);
    ld rad = atan(c / a);
    cout << setprecision(20) << fixed << rad * 180.0 / M_PI;
  }
}
