#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  ll ans = 0;
  if(a == 0) ans = 0;
  else if(b == 0) ans = n;
  else if(a + b >= n) {
    if(a >= n) ans = n;
    else ans = a;
  }
  else if(a + b < n) {
    ll rema = n % (a + b);
    ll div = n / (a + b);
    if(a > rema) ans = (div*a) + rema;
    else ans = (div*a) + a;
  }
  cout << ans << endl;
  return 0;
}