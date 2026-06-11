#include <bits/stdc++.h>
using namespace std;

int main() {
  int K;
  cin >> K;
  vector<long> ans;
  function<void(long)> dfs = [&](long n) -> void {
    if (n > 3234566667) return;
    ans.push_back(n);
    for (int next = max(0L, n % 10 - 1); next <= min(9L, n % 10 + 1); next++) {
      dfs(n * 10 + next);
    }
  };
  for (int i = 1; i <= 9; i++) dfs(i);
  sort(ans.begin(), ans.end());
  cout << ans.at(K - 1) << "\n";
}