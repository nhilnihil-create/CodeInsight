#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

vector<ll> divisors(ll n) {
  vector<ll> D;
  for (ll i=1; i*i<=n; i++) {
    if (n%i==0) {
      D.push_back(i);
      if (i*i!=n) D.push_back(n/i);
    }
  }
  return D;
}

int main() {
  ll n; cin >> n;
  int ans = 0;
  auto D = divisors(n);
  for (auto d: D) {
    ll m = n;
    if (d == 1) continue;
    while (m%d==0) m /= d;
    ans += m%d == 1;
  }

  // 1以外
  ans += divisors(n-1).size()-1;
  cout << ans << endl;
  return 0;
}
