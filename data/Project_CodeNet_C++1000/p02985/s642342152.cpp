#include<bits/stdc++.h>
using namespace std;

using LL = long long;
using Graph = vector<vector<int>>;

const LL M = 1e9+7;
int N;
LL K;
Graph G;

LL dfs(auto pre, auto cur, auto k) {
  LL res = k;
  k = max(k - 1, K - 2);
  for(auto nex: G[cur]) if(nex != pre) (res *= dfs(cur, nex, k--)) %= M;
  return res;
}

int main() {
  cin >> N >> K;
  G.resize(N);
  for(auto i = 1; i < N; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }

  cout << dfs(0, 0, K) << endl;
}
