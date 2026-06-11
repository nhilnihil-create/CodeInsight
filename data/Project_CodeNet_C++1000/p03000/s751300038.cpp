#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, X;
  cin >> N >> X;
  vector<int> L(N);
  for (int i = 0; i < N; i++) cin >> L[i];
  int ans = 0, distance = 0;
  for (int i = 0; i < N; i++) {
    distance += L[i];
    if (distance > X) {
      ans += i+1;
      break;
    }
    if (i == N-1) ans += N+1;
  }
  cout << ans << endl;
}
