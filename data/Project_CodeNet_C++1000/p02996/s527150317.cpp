#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> vp;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    vp.push_back(make_pair(b, a));
  }

  sort(vp.begin(), vp.end());

  int tm = 0;
  string ans = "Yes";
  for (auto q : vp) {
    tm += q.second;
    if (tm > q.first) {
      ans = "No";
      break;
    }
  }

  cout << ans << endl;
  return 0;
}
