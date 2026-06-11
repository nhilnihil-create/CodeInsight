#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> relation;
vector<bool> seen;

int dfs(int x) {
  seen.at(x) = true;
  int count = 0;
  for(int i = 0; i < relation.at(x).size(); i++) {
    if(seen.at(relation.at(x).at(i))) {
      continue;
    }
    count += dfs(relation.at(x).at(i));
  }
  count++;
  return count;
}

int main() {
  cin >> N >> M;
  relation.assign(N, {});
  seen.assign(N, false);
  for(int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    relation.at(a).push_back(b);
    relation.at(b).push_back(a);
  }
  int ans = 0;
  for(int i = 0; i < N; i++) {
    if(seen.at(i)) {
      continue;
    }
    int x = dfs(i);
    if(x > ans) {
      ans = x;
    }
  }
  cout << ans << endl;
}