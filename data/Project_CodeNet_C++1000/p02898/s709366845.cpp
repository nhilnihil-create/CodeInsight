#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    cin >> h.at(i);
  }
  
  int ans = 0;
  for (int hi : h) {
    if (hi >= k) ans++;
  }
  cout << ans << endl;
}