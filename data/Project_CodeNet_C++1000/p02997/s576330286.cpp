#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int m = n * (n - 1) / 2 - k;
  if(m < n-1) {
    cout << -1 << endl;
    return 0;
  }
  vector<pair<int, int>> ans;
  for(int i=2;i<=n;i++) {
    ans.emplace_back(make_pair(1, i));
  }
  for(int i=2;i<=n;i++) {
    for(int j=i+1;j<=n;j++) {
      if(ans.size() == m) break;
      ans.emplace_back(make_pair(i, j));
    }
    if(ans.size() == m) break;
  }
  cout << m << endl;
  for(auto& edge : ans) cout << edge.first << " " << edge.second << endl;
  return 0;
}
