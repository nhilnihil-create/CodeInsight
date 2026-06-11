#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> works(m+1);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    if (a > m) continue;
    works[a].push_back(b);
  }
  ll ans = 0;
  priority_queue<int> que;
  for (auto w : works) {
    for (auto x : w) {
      que.push(x);
    }
    if (!que.empty()) {
      ans += que.top();
      que.pop();
    }
  }
  cout << ans << '\n';
  return 0;
}