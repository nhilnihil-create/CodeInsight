#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using Pii = pair<ll, ll>;
using Pll = pair<ll, ll>;
#define rep(i, begin, n) for (ll i = begin; i < n; i++)
#define repe(i, begin, n) for (ll i = begin; i <= n; i++)
#define repr(i, begin, n) for (ll i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (ll i = begin; i >= end; i--)

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

const ll inf = 1000000007;
const ll MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------

int N, K;

int main() {
  cin >> N >> K;

  int ma = (N - 1) * (N - 2) / 2;
  if (K > ma) {
    cout << -1;
    return 0;
  }

  int diff = ma - K;

  int M = N - 1 + diff;

  cout << M << "\n";
  rep(i, 0, N - 1) { cout << 1 << " " << i + 2 << "\n"; }

  if (diff == 0) return 0;

  int cnt = 0;
  repe(i, 2, N - 1) {
    repe(j, i + 1, N) {
      cout << i << " " << j << "\n";
      ++cnt;
      if (cnt == diff) break;
    }
    if (cnt == diff) break;
  }
}
