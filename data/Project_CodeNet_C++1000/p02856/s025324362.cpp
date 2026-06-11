#include <iostream>

using namespace std;

typedef long long ll;

int main () {
  ios::sync_with_stdio(false);
  
  int m;
  cin >> m;

  ll sumd = 0, len = 0;
  for (int i = 0; i < m; i++) {
    ll cnt, dg;
    cin >> dg >> cnt;
    sumd += cnt * dg;
    len += cnt;
  }

  ll ans = len - 1 + sumd / 9;
  if (sumd % 9 == 0) ans--;

  cout << ans << endl;
}
