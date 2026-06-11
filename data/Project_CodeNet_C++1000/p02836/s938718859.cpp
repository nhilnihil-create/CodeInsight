#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;

  if (s.size() == 1) {
    cout << 0 << endl;
    return 0;
  }

  // 分割後リバースして比較
  // 100以下なので間に合う
  string s1 = s.substr(0, s.size()/2);
  string s2 = s.substr((s.size() + 1)/2, s.size());
  reverse(s2.begin(), s2.end());

  int count = 0;
  rep(i, s1.size()) {
    if (s1[i] != s2[i]) {
      count++;
    }
  }

  cout << count << endl;

  return 0;
}
