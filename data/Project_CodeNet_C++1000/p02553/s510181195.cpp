#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll a, b, c, d;

  cin >> a >> b >> c >> d;

  ll ans = LLONG_MIN;

  ans = max(ans, max(a * c, a * d));
  ans = max(ans, max(b * c, b * d));

  cout << ans << endl;

  return 0;
}
