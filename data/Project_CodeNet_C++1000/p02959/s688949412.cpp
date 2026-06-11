#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <set>
using namespace std;
typedef long long ll;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n+1);
  vector<ll> b(n);

  for (ll i = 0; i <= n; i++) {
    cin >> a[i];
  }

  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    cin >> b[i];

    if(a[i] + a[i+1] >= b[i]) {
      ans += b[i];
      if (b[i] >= a[i]) {
        a[i+1] = a[i+1] - (b[i] - a[i]);
        a[i] = 0;
      } else {
        a[i] = a[i] - b[i];
      }
    } else {
      ans += a[i] + a[i+1];
      a[i] = 0;
      a[i+1] = 0;
    }
  }
  cout << ans << endl;
}