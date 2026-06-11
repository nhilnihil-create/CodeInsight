#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll h, ans = 1;
  cin >> h;
  while (ans <= h) ans *= 2;
  cout << ans - 1 << endl;
  return 0;
}
