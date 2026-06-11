#include<bits/stdc++.h>
using namespace std;

void solve() {
  long long H1, M1, H2, M2, K;
  cin >> H1 >> M1 >> H2 >> M2 >> K;

  long long res = (H2 - H1) * 60 + (M2 - M1) - K;
  cout << res << "\n";
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

    solve();

  return 0;
}
