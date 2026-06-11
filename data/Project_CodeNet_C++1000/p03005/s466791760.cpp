#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  if (k == 1) {
    puts("0");
  } else {
    int ans = n - k;
    cout << ans << '\n';
  }
  return 0;
}
