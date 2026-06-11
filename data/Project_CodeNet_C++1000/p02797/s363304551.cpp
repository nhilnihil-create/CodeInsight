#include <bits/stdc++.h>

using namespace std;

constexpr int INF = (int)1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k, s;
  cin >> n >> k >> s;
  if (s == INF) {
    vector<int> ans(n, 1);
    for (int i = 0; i < k; i++) {
      ans[i] = INF;
    }
    for (const auto& e : ans) {
      cout << e << ' ';
    }
    cout << '\n';
    return 0;
  }
  vector<int> ans(n, INF);
  for (int i = 0; i < k; i++) {
    ans[i] = s;
  }
  for (const auto& e : ans) {
    cout << e << ' ';
  }
  cout << '\n';
  return 0;
}
