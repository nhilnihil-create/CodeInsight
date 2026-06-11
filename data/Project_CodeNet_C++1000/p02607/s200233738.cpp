#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int in;cin >> in;
    if (in & 1 && i & 1) ans++;
  }
  cout << ans;
}            
