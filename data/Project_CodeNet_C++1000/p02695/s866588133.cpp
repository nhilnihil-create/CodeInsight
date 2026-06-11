#include<bits/stdc++.h>
using namespace std;

struct Edge {int a, b, c, d;};
int N, M, Q;
vector<vector<Edge>> G;

int score(auto& A) {
  int res = 0;
  for(auto& E: G) for(auto& e: E) if(A[e.b] - A[e.a] == e.c) res += e.d;
  return res;
}
int dfs(auto i, auto A) {
  if(i == N) return score(A);
  auto res = 0;
  for(auto j=A[i-1]; j<=M; ++j) {
    A[i] = j;
    res = max(res, dfs(i+1, A));
  }
  return res;
}
int main() {
  cin >> N >> M >> Q;
  G.resize(N);
  for(auto i=0; i<Q; ++i) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    --a; --b;
    G[b].push_back({a, b, c, d});
  }
  cout << dfs(1, vector<int>(N,1)) << endl;
}
