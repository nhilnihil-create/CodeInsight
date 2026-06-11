#include <bits/stdc++.h>

using namespace std;
typedef pair<string, int> P;

int main() {
  int n;
  cin >> n;
  
  vector<P> st(n);
  for (int i = 0; i < n; ++i) {
    string s;
    int t;
    cin >> s >> t;
    st[i] = P(s, t);
  }
  
  string x;
  cin >> x;
  bool should_add = false;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (should_add) ans += st[i].second;
    if (st[i].first == x) should_add = true;
  }
  cout << ans << endl;
  return 0;
}