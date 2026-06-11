#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector<int> v;
vector<vector<int>> tree;
vector<bool> visited;

void dfs(int i = 1) {
  for (int j : tree[i]) {
    if (visited[j]) continue;
    visited[j] = 1;
    v[j] += v[i];
    dfs(j);
  }
}


int main() {
  ll N, Q, a, b, p, x;
  cin >> N >> Q;

  v.resize(N+1);
  tree.resize(N+1);
  visited.resize(N+1);
  for (int i = 1; i != N; ++i) {
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  for (int i = 0; i != Q; ++i) {
    cin >> p >> x;
    v[p] += x;
  }

  visited[1] = 1;
  dfs();

  for (int i = 1; i <= N; ++i) {
    cout << (i > 1 ? " " : "") << v[i];
  }
  cout << endl;
}
