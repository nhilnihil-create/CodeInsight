#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int K;
  cin >> K;
  int cur = 0;
  for (int i = 0; i < K; i++) {
    cur = cur * 10 + 7;
    cur %= K;
    if (cur == 0) {
      cout << i + 1 << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
  return 0;
}
