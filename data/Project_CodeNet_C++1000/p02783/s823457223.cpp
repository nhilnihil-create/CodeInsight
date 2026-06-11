#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, ans;
  cin >> a >> b;
  ans = 0;
  if (a % b != 0) ans++;
  ans += a / b;
  cout << ans << endl;
  return 0;
}
