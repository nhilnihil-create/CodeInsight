#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int n;
  cin >> n;

  vector<int> plus, minus;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if(a >= 0) plus.push_back(a);
    else minus.push_back(a);
  }
  sort(plus.rbegin(), plus.rend());
  sort(minus.begin(), minus.end());

  if(plus.empty()) {
    plus.push_back(minus.back());
    minus.pop_back();
  }
  if(minus.empty()) {
    minus.push_back(plus.back());
    plus.pop_back();
  }

  vector<pair<int,int>> ans;
  for (int i = 1; i < plus.size(); i++) {
    ans.emplace_back(minus[0], plus[i]);
    minus[0] -= plus[i];
  }
  ans.emplace_back(plus[0], minus[0]);
  plus[0] -= minus[0];
  for (int i = 1; i < minus.size(); i++) {
    ans.emplace_back(plus[0], minus[i]);
    plus[0] -= minus[i];
  }
  cout << plus[0] << endl;
  for (auto it : ans) cout << it.first << " " << it.second << endl;
}