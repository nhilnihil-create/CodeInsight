#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;

  int x = n * 100 / 108;

  while (x * 108 / 100 < n) {
    x++;
  }
  if (x * 108 / 100 == n) cout << x << endl;
  else cout << ":(" << endl;

  return 0;
}