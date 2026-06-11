#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  int n; cin >> n;
  ll ans = 0;
  for(int i = 1; i < n+1; ++i) {
    int j = 1;
    while(i*j <= n) ans += i*(j++);
  }
  cout << ans << "\n";
  return 0;
}