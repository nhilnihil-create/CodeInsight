#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
using pii = pair<int, int>;

bool comp(pii a, pii b) { return a.second < b.second; }
signed main() {
  int n;
  cin >> n;
  vector<int> x(n), l(n);
  vector<pair<int, int>> robot(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> l[i];
    robot[i] = make_pair(x[i] - l[i], x[i] + l[i]);
  }

  sort(robot.begin(), robot.end(), comp);

  int res = 0;
  int cur = -99999999;
  for (int i = 0; i < n; ++i) {
    if (cur > robot[i].first) continue;
    ++res;
    cur = robot[i].second;
  }
  cout << res << endl;
}