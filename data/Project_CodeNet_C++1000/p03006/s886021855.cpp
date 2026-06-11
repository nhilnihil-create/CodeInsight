#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<pair<int, int>> x(n);
  for (int i = 0; i < n; i++) cin >> x.at(i).first >> x.at(i).second;
  
  map<pair<int, int>, int> mp;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      int a = x.at(i).first - x.at(j).first;
      int b = x.at(i).second - x.at(j).second;
      if (a < 0) {
        a *= -1;
        b *= -1;
      }
      else if(a == 0) b = abs(b);
      mp[make_pair(a, b)]++;
    }
  }
  
  int ans = n;
  for (auto i : mp) ans = min(ans, n - i.second);
  
  cout << ans << '\n';
}