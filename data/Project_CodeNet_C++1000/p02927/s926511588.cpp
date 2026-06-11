#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int M, D;
  cin >> M >> D;

  int ans = 0;
  for (int i = 1; i <= M; i++) {
    for (int j = 2; j <= D; j++) {
      if ((i == (j / 10) * (j % 10)) && j / 10 >= 2 && j % 10 >= 2) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}