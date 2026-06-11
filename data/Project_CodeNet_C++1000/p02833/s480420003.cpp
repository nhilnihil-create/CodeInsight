#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define endl '\n'

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
 
  ll n;
  cin >> n;
  if (n&1) {
    cout << 0 << endl;
    return 0;
  }
  ll p = 5;
  ll ans = 0;
  while (p < n) {
    p *= 5;
  }

  while (p > 1) {
    ans += (n/p)/2;
    p /= 5;
  }
//  ans += n/50;

  cout << ans << endl;
}
