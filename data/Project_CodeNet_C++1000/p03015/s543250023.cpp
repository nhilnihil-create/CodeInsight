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

string L;
ll dp0[101010], dp1[101010];

int main() {
  cin >> L;

  dp0[0] = 1;
  dp1[0] = 2;
  int len = L.size();
  rep(i, 1, len) {
    if (L[i] == '0') {
      dp0[i] = dp0[i - 1] * 3 % MOD;
      dp1[i] = dp1[i - 1];
    } else {
      dp0[i] = (dp0[i - 1] * 3) % MOD + dp1[i - 1];
      dp0[i] %= MOD;
      dp1[i] = dp1[i - 1] * 2 % MOD;
    }
  }

  cout << (dp0[len - 1] + dp1[len - 1]) % MOD;
}
