#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;
using ll = long long;

int main() {
  ll a, b, c;
  cin >> a >> b >> c;

  ll l = 4 * a * b;
  ll r = c - (a + b);
  if (0 < r && l < r * r) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
