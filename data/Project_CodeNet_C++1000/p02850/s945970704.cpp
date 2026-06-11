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

struct edge {
  int to, color;
};

int N;
vector<edge> Graph[101010];
int A[101010], B[101010];
int K;
map<Pii, int> ans;

void dfs(int cur, int from, int from_color) {
  int cnt = 1;
  for (int i = 0; i < Graph[cur].size(); ++i) {
    edge e = Graph[cur][i];
    if (cnt == from_color) ++cnt;

    if (e.to == from) {
      Graph[cur][i] = edge{e.to, from_color};
      ans[Pii(cur, e.to)] = from_color;
      continue;
    } else {
      Graph[cur][i] = edge{e.to, cnt};
      ans[Pii(cur, e.to)] = cnt;
      dfs(e.to, cur, cnt);
      ++cnt;
    }
  }
  chmax(K, cnt - 1);
}

int main() {
  cin >> N;
  rep(i, 0, N - 1) {
    int a, b;
    cin >> a >> b;
    Graph[a].push_back(edge{b, 0});
    Graph[b].push_back(edge{a, 0});
    A[i] = a;
    B[i] = b;
  }

  dfs(1, 0, 0);

  cout << K << "\n";
  rep(i, 0, N - 1) { cout << ans[Pii(A[i], B[i])] << "\n"; }
}
