/**
 *    author:  morato
 *    created: 19.09.2020 17:29:39
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
  int f = 0;
  for (int i = 0; i < n - 2; i++) {
    if (a[i] == b[i] && a[i + 1] == b[i + 1] && a[i + 2] == b[i + 2]) {
      f = 1;
    }
  }
  cout << (f ? "Yes\n" : "No\n");
  return 0;
}