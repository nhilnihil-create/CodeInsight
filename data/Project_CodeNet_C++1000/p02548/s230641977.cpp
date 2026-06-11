#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
  freopen("c.in", "r", stdin);
  freopen("c.out", "w", stdout);
#endif
  int N, ans = 0;
  cin >> N;
  for (int i = 1; i <= N; ++i) {
    ans += N / i;
    if (N % i == 0) --ans;
  }
  cout << ans << endl;
  return 0;
}