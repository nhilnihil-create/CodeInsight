#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//cout << fixed << setprecision(17) << res << endl;                                                    
int main() {
  ll n;
  cin >> n;
  vector<ll> A(n+1);
  for (auto & a : A) cin >> a;

  ll total = 0;
  for (auto a : A) total += a;


  ll res = 0;
  ll cur = 1;
  for (ll i = 0; i <= n; ++i) {
    if (cur < A[i]) {
      cout << -1 << endl;
      return 0;
    }
    res += min(cur, total);
    cur = min(cur, total) - A[i];
    total -= A[i];
    cur *= 2;
  }
  cout << res << endl;
  return 0;
}