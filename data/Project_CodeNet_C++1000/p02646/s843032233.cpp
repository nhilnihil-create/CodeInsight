#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T& a, T b) {
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

int a, v, b, w, t;

int main() {
  cin >> a >> v >> b >> w >> t;

  if (v <= w) {
    cout << "NO" << endl;
    return 0;
  }

  int tt = (abs(a - b) + (v - w) - 1) / (v - w);
  bool can = tt <= t;
  if (can) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
