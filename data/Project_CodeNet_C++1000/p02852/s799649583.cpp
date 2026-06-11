#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  vector<int> ans;
  int i = 0;
  while (i < n) {
    for (int j = min(m, n-i); j > 0; --j) {
      if (s[i+j] == '0') {
        i += j;
        ans.push_back(j);
        break;
      }
      if (j == 1) {
        cout << -1 << endl;
        return 0;
      }
    }
  }
  reverse(ans.begin(), ans.end());
  rep(i, ans.size()) {
    if (i) cout << " ";
    cout << ans[i];
  }
  cout << endl;
  return 0;
}