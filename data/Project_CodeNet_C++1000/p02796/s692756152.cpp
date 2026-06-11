#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  vector<pair<ll, ll>> robot(n);
  for (int i = 0; i < n; i++) {
    cin >> robot[i].first >> robot[i].second;
  }

  sort(robot.begin(), robot.end());

  ll before_limit = - 1e10;
  int ans = 0;

  for (int i = 0; i < n; i++) {
    if (before_limit <= robot[i].first - robot[i].second) {
      ans++;
      before_limit = robot[i].first + robot[i].second;
    }
    else {
      if (robot[i].first + robot[i].second < before_limit) {
        before_limit = robot[i].first + robot[i].second;
      }
    }
  }

cout << ans << endl;

return 0;
}