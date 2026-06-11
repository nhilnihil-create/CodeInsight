#include <iostream>
#include <map>
#include <vector>

using namespace std;

int K;
vector<vector<int>> Tree;
map<pair<int, int>, int> mp;

void dfs(int cur_v, int par_v, int prev_c) {
  int c = 1;
  for (auto nxt_v : Tree[cur_v]) {
    if (nxt_v == par_v) {
      continue;
    }
    if (c == prev_c) {
      c++;
    }
    mp[make_pair(cur_v, nxt_v)] = c;
    mp[make_pair(nxt_v, cur_v)] = c;
    dfs(nxt_v, cur_v, c);
    c++;
  }
}

int main() {
  int N;
  cin >> N;

  Tree = vector<vector<int>>(N);
  vector<pair<int, int>> Edge(N);

  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    Tree[a].push_back(b);
    Tree[b].push_back(a);
    Edge[i] = make_pair(a, b);
  }

  K = 0;
  for (int i = 0; i < N; i++) {
    K = max(K, (int)Tree[i].size());
  }

  dfs(0, -1, -1);

  cout << K << endl;
  for (int i = 0; i < N - 1; i++) {
    cout << mp[Edge[i]] << endl;
  }

  return 0;
}