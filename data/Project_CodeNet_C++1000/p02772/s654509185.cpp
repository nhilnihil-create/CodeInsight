/**
 *    author:  morato
 *    created: 25.08.2020 20:06:44
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int f = 1;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x % 2 == 0) {
      f &= (x % 3 == 0 || x % 5 == 0);
    }
  }
  cout << (f ? "APPROVED\n" : "DENIED\n");
  return 0;
}