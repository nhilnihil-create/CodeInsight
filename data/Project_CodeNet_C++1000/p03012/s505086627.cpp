#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> wi(n);
  for (int i = 0; i < n; i++) cin >> wi.at(i);
  
  int ans = 10000;
  for (int i = 0; i < n; i++) {
    int l = 0;
    int r = 0;
    for (int j = 0; j <= i; j++) l += wi.at(j);
    for (int j = i+1; j < n; j++) r += wi.at(j);
    ans = min(ans, abs(l-r));
  }
  cout << ans << endl;
}