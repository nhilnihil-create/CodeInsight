#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<string> s(n);
  vector<int> t(n);
  for (int i = 0; i < n; i++) cin >> s.at(i) >> t.at(i);
  
  string x;
  cin >> x;
  
  int ans = 0;
  bool sleep = false;
  for (int i = 0; i < n; i++) {
    if (sleep) ans += t.at(i);
    if (s.at(i) == x) sleep = true;
  }
  
  cout << ans << '\n';
}