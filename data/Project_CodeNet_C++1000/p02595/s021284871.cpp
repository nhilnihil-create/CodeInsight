#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main (void) {
  ios::sync_with_stdio(false);cin.tie(0);
  int n, res = 0;
  ll d;
  cin >> n >> d;
  d *= d;
  for (int i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    if (x * x + y * y <= d)
      res++;
  }
  cout << res << '\n';
  return 0;
}

