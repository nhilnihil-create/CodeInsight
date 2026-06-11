#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n;
  cin >> n;
  int res = 0;
  for (int x, i = 1; i <= n; i++) {
    cin >> x;
    res += x % 2 && i % 2;
  } 
  cout << res << '\n';
  return 0;
}