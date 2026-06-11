#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;
  
  int v[4] = {INT_MAX, INT_MIN, INT_MAX, INT_MIN};
  ii pt[4];

  int x, y;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;

    ii p = make_pair(x, y);
    if (x + y < v[0]) pt[0] = p, v[0] = x + y;
    if (x + y > v[1]) pt[1] = p, v[1] = x + y;;
    if (x - y < v[2]) pt[2] = p, v[2] = x - y;;
    if (x - y > v[3]) pt[3] = p, v[3] = x - y;;
  }

  ll ans = 0;
  for (int i = 0; i < 4; i++)
    for (int j = i + 1; j < 4; j++)
      ans = max(ans, 0LL + abs(pt[i].first - pt[j].first) + abs(pt[i].second - pt[j].second));

  cout << ans << endl;

  return 0;
}
