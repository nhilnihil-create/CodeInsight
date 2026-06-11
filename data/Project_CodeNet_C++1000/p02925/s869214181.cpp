#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep2(i, m, n) for(int i=int(m); i<int(n); i++)
#define rep(i, n) rep2(i, 0, n)
#define ALL(a) a.begin(), a.end()
using ll = long long;
using ld = long double;
using V = vector<int>;
using Vll = vector<ll>;
using Vld = vector<ld>;
using VV = vector<V>;
using VVll = vector<Vll>;
using VVld = vector<Vld>;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
using Pld = pair<ld, ld>;
const int INF = 1<<30;
const ll INFll = 1ll<<62;
const ld EPS = 1e-10;
const int MOD = int(1e9)+7;
template<typename T> inline bool chmin(T& a, T b) {if(a>b) {a=b; return true;} return false;}
template<typename T> inline bool chmax(T& a, T b) {if(a<b) {a=b; return true;} return false;}

using Graph = vector<vector<int>>;

int N;
int node(int i, int j){
  if (i < j) swap(i, j);
  return i*(i-1)/2 + j;
}


int main() {
  cin >> N;
  VV A(N, V(N-1));
  rep(i, N) rep(j, N-1) {
    cin >> A[i][j];
    A[i][j]--;
  }

  int NN = N*(N-1)/2;
  Graph G(NN, V());
  V indeg(NN);

  rep(i, N) rep(j, N-2) {
    G[node(i, A[i][j])].push_back(node(i, A[i][j+1]));
    indeg[node(i, A[i][j+1])]++;
  }

  queue<int> que;
  rep(u, NN) {
    if (indeg[u] == 0) que.push(u);
  }

  vector<int> order;
  while (!que.empty()) {
    auto u = que.front(); que.pop();
    order.push_back(u);
    for (auto v : G[u]) {
      indeg[v]--;
      if (indeg[v] == 0) que.push(v);
    }
  }

  if (order.size() < G.size()) {
    cout << -1 << endl;
    return 0;
  }

  V dp(NN);
  for (auto u : order) {
    for (auto v : G[u]) {
      chmax(dp[v], dp[u]+1);
    }
  }

  int ans = *max_element(ALL(dp)) + 1;
  cout << ans << endl;
  return 0;
}
