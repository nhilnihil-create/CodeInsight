#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  string s;
  cin >> n >> m >> s;
  vector<int> sugoroku;
  bool yes = true;
  for(int i=0;i<n+1;i++) {
    if(s[i] == '0') sugoroku.emplace_back(i);
  }
  int si = sugoroku.size();
  vector<int> turn(si);
  for(int i=si-1;i>=0;i--) {
    if(i == si - 1) {
      turn[i] = 0;
      continue;
    }
    auto it = upper_bound(sugoroku.begin(), sugoroku.end(), sugoroku[i] + m);
    it = prev(it);
    int dist = distance(sugoroku.begin(), it);
    if(dist == i) {
      yes = false;
      break;
    }
    turn[i] = turn[dist] + 1;
  }
  if(!yes) {
    cout << -1 << endl;
    return 0;
  }
  vector<int> ans;
  int pre = 0;
  int target = turn[0] - 1;
  for(int i=0;i<si;i++) {
    if(turn[i] != target) continue;
    else {
      target--;
      ans.emplace_back(sugoroku[i] - sugoroku[pre]);
      pre = i;
    }
  }
  for(auto& el : ans) cout << el << endl;
  return 0;
}
