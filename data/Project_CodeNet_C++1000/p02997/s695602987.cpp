#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  int mx = (N - 1) * (N - 2) / 2;
  if (K > mx) return cout << -1 << "\n", 0;
  int cnt = mx - K;
  cout << N - 1 + cnt << "\n";
  for (int i = 2; i <= N; i++) cout << 1 << " " << i << "\n";
  for (int i = 2; i < N; i++) {
    for (int j = i + 1; j <= N; j++, cnt--) {
      if (cnt > 0) cout << i << " " << j << "\n";
    }
  }
}