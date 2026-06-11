#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n,k;
  cin >> n >> k;

  if(k > (n - 1) * (n - 2) / 2) {
    cout << -1 << '\n';
    return 0;
  }

  vector<pair<int,int>> ans;
  for (int i = 2; i <= n; i++) {
    ans.emplace_back(1, i);
  }
  int tot = (n - 1) * (n - 2) / 2;
  for (int i = 2; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if(tot == k) break;
      ans.emplace_back(i, j);
      tot--;
    }
    if(tot == k) break;
  }

  cout << ans.size() << '\n';
  for(auto it : ans) {
    cout << it.first << " " << it.second << '\n';
  }
}