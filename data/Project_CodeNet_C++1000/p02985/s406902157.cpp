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

ll N, K;
vector<ll> Graph[101010];
ll used[101010];
ll ans = 1;

void dfs(ll cur, ll from) {
  if (from != 0) ++used[cur];

  ans *= K - used[from];
  ans %= MOD;
  ++used[cur];
  ++used[from];

  for (auto nv : Graph[cur]) {
    if (nv == from) continue;

    dfs(nv, cur);
  }
}

int main() {
  cin >> N >> K;
  rep(i, 0, N - 1) {
    ll a, b;
    cin >> a >> b;
    Graph[a].push_back(b);
    Graph[b].push_back(a);
  }

  dfs(1, 0);

  cout << ans;
}
