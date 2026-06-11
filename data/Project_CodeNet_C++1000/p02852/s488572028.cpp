#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  vector<int> ans;
  int last = 0, biggest = 0;
  for (int i = 1; i <= n; i++) {
    if (i - last > m) {
      if (biggest == 0) {
        cout << -1 << endl;
        return 0;
      } else {
        last += biggest;
        ans.push_back(biggest);
        biggest = 0;
      }
    }
    if (s.at(i) == '0') {
      biggest = i - last;
    }
  }
  if (biggest) ans.push_back(biggest);
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < ans.size(); i++) {
    cout << ans.at(i);
    if (i == ans.size() - 1) {
      cout << endl;
    } else {
      cout << " ";
    }
  }
}
