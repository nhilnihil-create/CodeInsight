#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int l, r, d;
  cin >> l >> r >> d;
  if (l % d) 
    l = l + (d - l % d);
  if (l > r) {
    cout << "0\n";
    return 0;
  }
  cout << max(0, (r - l) / d) + 1 << '\n';
  return 0;
}