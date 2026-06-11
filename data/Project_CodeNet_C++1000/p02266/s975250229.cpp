#include <bits/stdc++.h>
using namespace std;
int main() {
  stack<int> S1;
  stack<pair<int, int>> S2;
  string map;
  cin >> map;
  for (int i = 0; i < map.size(); i++) {
    auto c = map.at(i);
    if (c == '\\') {
      S1.push(i);
    } else if (c == '/' && !S1.empty()) {
      auto idx_corr = S1.top();
      S1.pop();
      auto area_next = i - idx_corr;
      while (!S2.empty() && idx_corr < S2.top().first) {
        area_next += S2.top().second;
        S2.pop();
      }
      S2.push(make_pair(idx_corr, area_next));
    }
  }

  int A = 0, k = S2.size();
  string ans = "";
  for (size_t i = 0; i < k; i++) {
    A += S2.top().second;
    ans = " " + to_string(S2.top().second) + ans;
    S2.pop();
  }

  cout << A << endl;
  cout << k << ans << endl;
}

