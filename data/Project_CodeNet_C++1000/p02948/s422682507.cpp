#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> J(100001);
  for (int a, b; cin >> a >> b;) J.at(a).push_back(b);
  priority_queue<int> Q;
  int ans = 0;
  for (int i = 1; i <= M; i++) {
    for (auto j : J.at(i)) Q.push(j);
    if (Q.size()) ans += Q.top(), Q.pop();
  }
  cout << ans << "\n";
}