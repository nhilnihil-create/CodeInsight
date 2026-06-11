#include <bits/stdc++.h>
using namespace std;

long aps(long a, long d, long n) {
  return n * (2 * a + (n - 1) * d) / 2;
}

int main() {
  int N;
  cin >> N;
  long ans = 0;
  for (int i = 1; i <= N; i++) {
    ans += aps(1, 1, i);
  }
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    if (u > v) swap(u, v);
    ans -= (long) u * (N - v + 1);
  }
  cout << ans << "\n";
}