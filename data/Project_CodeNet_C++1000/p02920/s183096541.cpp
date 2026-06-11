#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> s(1 << n);
  for (int i = 0; i < (1 << n); ++i) cin >> s[i];
  multiset<int> ms(s.begin(), s.end());
  vector<int> t(1, *max_element(s.begin(), s.end()));
  bool ok = true;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < (1 << i); ++j) {
      auto it = ms.lower_bound(t[j]);
      if (it == ms.begin()) {
        cout << "No\n";
        return 0;
      }
      t.push_back(*prev(it));
      ms.erase(prev(it));
    }
    sort(t.begin(), t.end(), greater<int>());
  }
  cout << "Yes\n";
}
