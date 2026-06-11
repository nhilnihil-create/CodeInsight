#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  int n_max = pow(2, n);
  multiset<int> s;
  for (int i = 0; i < n_max; i++) {
    int tmp;
    cin >> tmp;
    s.insert(-tmp);
  }
  
  vector<int> x;
  x.emplace_back(*s.begin());
  s.erase(s.begin());
  
  for (int i = 1; i <= n; i++) {
    sort(x.begin(), x.end());
    int loop_end = x.size();
    for (int j = 0; j < loop_end; j++) {
      auto it = s.upper_bound(x.at(j));
      if (it == s.end()) {
        cout << "No\n";
        return 0;
      }
      x.emplace_back(*it);
      s.erase(it);
    }
  }
  
  cout << "Yes\n";
  return 0;
}