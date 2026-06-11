#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll k, q; cin >> k >> q;
  vector<ll> d(k);
  for (int i = 0; i < k; ++i) cin >> d[i];
  
  while (q--) {
    ll n, x, m; cin >> n >> x >> m;
    ll xmod = x % m;
    vector<ll> dmod(k);
    ll sum = 0, cnt0 = 0;
    for (int i = 0; i < k; ++i) {
      dmod[i] = d[i] % m;
      sum += dmod[i];
      if (dmod[i] == 0) ++cnt0;
    }
    
    int p = (n-1) / k;
    int q = (n-1) % k;
    sum *= p; sum += xmod;
    cnt0 *= p;
    
    for (int i = 0; i < q; ++i) {
      sum += dmod[i];
      if (dmod[i] == 0) ++cnt0;
    }
    
    cout << n-1 - (sum/m + cnt0) << endl;
  }
}