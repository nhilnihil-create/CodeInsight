// https://atcoder.jp/contests/abc175/tasks/abc175_d

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define DEBUG 1
#if DEBUG
  #define _GLIBCXX_DEBUG
  #define DUMP(a) REP(_i, a.size()) cout << a[_i] << (_i + 1 == a.size() ? "\n" : " ")
  #define DUMP2D(b) REP(_j, b.size()) DUMP(b[_j]); cout << endl
#else
  #define DUMP(a)
  #define DUMP2D(b)
#endif

//------------------------------------------------------------------------------
template <typename T>
bool chmax(T &a, const T& b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template <typename T>
bool chmin(T &a, const T& b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
//------------------------------------------------------------------------------

const int N_MAX = 5000;
const int K_MAX = 1e9;
const int C_I_MAX = 1e9;
const ll INF = 2e18;

int N, K;
vector<int> P;
vector<int> C;

vector<int> dist;
vector<ll> acc;

int main() {
  cin >> N >> K;
  P = vector<int>(N);
  REP(i, N) {
    cin >> P[i];
    P[i]--;
  }
  C = vector<int>(N);
  REP(i, N) cin >> C[i];

  ll ans = -INF;
  REP(i, N) {
    int v = i;
    dist = vector<int>(N, -1);
    acc = vector<ll>(N, 0);
    dist[v] = 0;
    FOR(j, 1, K) {
      int u = P[v];
      if (dist[u] < 0) {
        dist[u] = j;
        acc[u] = acc[v] + C[u];
      } else {
        ll ds = acc[v] + C[u] - acc[u];
        if (ds < 0) break;
        int dd = j - dist[u];
        int r = (K - j) / dd;
        if (r > 0) r--;
        j += r * dd;
        dist[u] = j;
        acc[u] = acc[v] + C[u] + r * ds;
      }
      // cout << "i:" << i << " j:" << j << " u:" << u << " score:" << acc[u] << endl;
      chmax(ans, acc[u]);
      v = u;
    }
  }

  cout << ans << endl;
}
