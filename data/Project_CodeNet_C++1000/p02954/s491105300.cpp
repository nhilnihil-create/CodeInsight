#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <vector>

#define int long long int
constexpr int INF = std::numeric_limits<int>::max();
constexpr int NINF = std::numeric_limits<int>::min();
using namespace std;

void solve() {
  string s;
  cin >> s;

  int a = 0;
  vector<int> ans(s.size(), 0);
  for (int i = 0 ; i < s.size(); i++) {
    if (s[i] == 'R') {
      a++;
    } else {
      ans[i] += a/2;
      ans[i-1] += a-a/2;
      a = 0;
    }
  }

  a = 0;
  for (int i = s.size() - 1 ; i >= 0; i--) {
    if (s[i] == 'L') {
      a++;
    } else {
      ans[i] += a/2;
      ans[i+1] += a-a/2;
      a = 0;
    }
  }

  for (int x : ans) {
    cout << x << " ";
  }
  cout << endl;
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
