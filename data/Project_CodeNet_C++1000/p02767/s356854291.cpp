#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> X(N);
  for (int i = 0; i < N; i++) cin >> X.at(i);
  int ans = 1e9;
  for (int i = 1; i <= 100; i++) {
    int sum = 0;
    for (auto x : X) sum += (i - x) * (i - x);
    ans = min(ans, sum);
  }
  cout << ans << "\n";
}