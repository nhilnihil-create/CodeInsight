#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  int n_max = pow(2, n);
  vector<int> s(n_max);
  multiset<int> st;
  for (int i = 0; i < n_max; i++) {
    cin >> s.at(i);
    s.at(i) *= -1;
    st.insert(s.at(i));
  }
  
  sort(s.begin(), s.end());
  
  vector<int> x;
  x.emplace_back(s.at(0));
  st.erase(st.find(s.at(0)));
  
  for (int i = 1; i <= n; i++) {
    vector<int> y;
    sort(x.begin(), x.end());
    for (int j = 0; j < x.size(); j++) {
      auto it = st.upper_bound(x.at(j));
      if (it == st.end()) {
        cout << "No\n";
        return 0;
      }
      y.emplace_back(x.at(j));
      y.emplace_back(*it);
      st.erase(it);
    }
    x = y;
  }
  
  cout << "Yes\n";
  return 0;
}