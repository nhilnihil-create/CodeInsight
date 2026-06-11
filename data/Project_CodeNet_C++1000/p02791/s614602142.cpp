#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> P(N);
  for (int i = 0; i < N; i++) cin >> P.at(i);
  int ans = 0;
  for (int i = 0, mi = INT_MAX; i < N; i++) {
    if (P.at(i) < mi) ans++;
    mi = min(mi, P.at(i));
  }
  cout << ans << "\n";
}