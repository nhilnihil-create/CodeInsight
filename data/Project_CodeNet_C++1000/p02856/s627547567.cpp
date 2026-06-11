#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;
  ll dc = 0, ds = 0;
  for (int i = 1; i <= n; i++) {
    ll a, b;
    cin >> a >> b;
    dc += b;
    ds += a * b;
  }

  cout << dc - 1 + (ds - 1) / 9 << endl;
}
