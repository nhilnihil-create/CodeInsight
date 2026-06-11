#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, m;
  cin >> n;
  vector<string> u(n);
  map<string, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> u[i];
    mp[u[i]]++;
  }
  cin >> m;
  vector<string> t(m);
  for (int i = 0; i < m; i++) {
    cin >> t[i];
  }
  bool f = true;
  for (int i = 0; i < m; i++) {
    if (mp[t[i]] == 0) {
      cout << "Unknown " << t[i] << endl;
    } else {
      if (f) {
        f = !f;
        cout << "Opened by " << t[i] << endl;
      } else {
        f = !f;
        cout << "Closed by " << t[i] << endl;
      }
    }
  }

  return 0;
}
