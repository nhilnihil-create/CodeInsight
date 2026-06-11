#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  int ans = 0;
  for (int i = 1; i <= N; i++) {
    if (((int)log10(i) + 1) % 2 == 1) ans++;
  }
  cout << ans << endl;
  return 0;
}