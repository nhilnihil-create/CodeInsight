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

int N, M;
vector<int> Graph[301010];
int S, T;
int dist[301010];

int main() {
  cin >> N >> M;
  rep(i, 0, M) {
    ll u, v;
    cin >> u >> v;
    Graph[3 * u].push_back(3 * v + 1);
    Graph[3 * u + 1].push_back(3 * v + 2);
    Graph[3 * u + 2].push_back(3 * v);
  }
  cin >> S >> T;

  rep(i, 0, 301010) { dist[i] = inf; }
  dist[S * 3] = 0;

  queue<int> que;
  que.push(S * 3);
  while (!que.empty()) {
    int cv = que.front();
    que.pop();

    for (auto nv : Graph[cv]) {
      if (dist[nv] != inf) continue;

      dist[nv] = dist[cv] + 1;
      que.push(nv);
    }
  }

  if (dist[T * 3] == inf) {
    cout << -1;
  } else if (dist[T * 3] % 3 != 0) {
    cout << -1;
  } else {
    cout << dist[T * 3] / 3;
  }
}
