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

int N;
vector<int> Graph[1010101];
int visited[1010101], finished[1010101];
vector<int> order;
int dist[1010101];

bool tsort(int cur) {
  visited[cur] = true;
  for (auto nv : Graph[cur]) {
    if (finished[nv]) continue;

    if (visited[nv]) return false;

    if (!tsort(nv)) return false;
  }
  visited[cur] = false;
  finished[cur] = true;
  order.push_back(cur);
  return true;
}

void calc_dist(int cur) {
  int res = 1;
  for (auto nv : Graph[cur]) {
    chmax(res, dist[nv] + 1);
  }
  dist[cur] = res;
}

int getidx(int i, int j) { return (i - 1) * N + j; }

int main() {
  cin >> N;
  repe(i, 1, N) {
    int prev;
    cin >> prev;
    rep(j, 1, N - 1) {
      int a;
      cin >> a;
      int pp = prev;
      int ii = i;
      int iii = i;
      int aa = a;
      if (ii > pp) {
        swap(ii, pp);
      }
      if (iii > aa) {
        swap(iii, aa);
      }
      Graph[getidx(ii, pp)].push_back(getidx(iii, aa));
      prev = a;
    }
  }

  repe(i, 1, N - 1) {
    repe(j, i + 1, N) {
      visited[getidx(i, j)] = false;
      finished[getidx(i, j)] = false;
    }
  }

  repe(i, 1, N - 1) {
    repe(j, i + 1, N) {
      if (finished[getidx(i, j)]) continue;

      if (!tsort(getidx(i, j))) {
        cout << -1;
        return 0;
      }
    }
  }

  int ans = 0;
  for (auto nv : order) {
    calc_dist(nv);
    chmax(ans, dist[nv]);
  }
  cout << ans;
}
