#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll k, q; cin >> k >> q;
  ll d[k];
  for (ll i = 0; i < k; i++) {
    cin >> d[i];
  }
  for (ll i = 0; i < q; i++) {
    ll n, x, m; cin >> n >> x >> m;
    x = x%m;
    ll D = 0;
    ll num0 = 0;
    for (ll i = 0; i < k; i++) {
      D += (d[i]%m);
      if (d[i]%m == 0) {num0++;}
    }
    ll dsum = ((n-1)/k)*D;
    ll num = ((n-1)/k)*num0;
    for (ll i = 0; i < ((n-1)%k); i++) {
      dsum += (d[i]%m);
      if (d[i]%m == 0) {num++;}
    }
    
    cout << n-1-((dsum+x)/m)-num << endl;
  }
}