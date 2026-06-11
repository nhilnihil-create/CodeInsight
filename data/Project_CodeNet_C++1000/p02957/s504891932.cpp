#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"

int main() {
  ll a, b;
  cin >> a >> b;
  if (abs(a - b) & 1) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  ll ans = (1ll * abs(a - b)) >> 1;
  ans = max(a, b) - ans;
  cout << abs(ans) << endl;
  return 0;
}