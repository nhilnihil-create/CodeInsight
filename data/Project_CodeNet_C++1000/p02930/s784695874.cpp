#include <bits/stdc++.h>
using namespace std;

void dfs(int v, int now, vector<bool> &used, vector<int> &zero, vector<int> &one, vector<vector<int>> &ans) {
  used[v] = true;
  if (now == 0) zero.emplace_back(v);
  else one.emplace_back(v);
  for (int i = v + 1; i < used.size(); i++) {
    if (!used[i] && ans[v][i] == -1) dfs(i, (now ^ 1), used, zero, one, ans);
  }
  return;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<vector<int>> ans(n, vector<int>(n, -1));
  
  for (int i = 1; i < n; i++) {
    vector<bool> used(n, false);
    vector<int> zero, one;
    for (int j = 0; j < n; j++) {
      if (!used[j]) dfs(j, 0, used, zero, one, ans);
    }
    if (one.size() == 0) break;
    for (int j = 0; j < zero.size(); j++) {
      for (int k = 0; k < one.size(); k++) {
        if (ans[zero[j]][one[k]] == -1) {
          ans[zero[j]][one[k]] = ans[one[k]][zero[j]] = i;
        }
      }
    }
  }
  
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (j > i + 1) cout << " ";
      cout << ans[i][j];
    }
    cout << '\n';
  }
}