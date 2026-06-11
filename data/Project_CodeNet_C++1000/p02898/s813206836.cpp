#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N, K;
  cin >> N >> K;

  int h;
  int ans = 0;
  rep(i, N) {
    cin >> h;
    if (h >= K) ans++;
  }
  cout << ans << endl;
  return 0;
}