#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;
const int INF = 1e9;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i = 0; i < n; i++) { 
    cin >> a[i];
  }
  ll sum = 0;
  for(int i = 0; i < n; i++) { 
    sum += a[i];
  }
  set<ll> candidates;
  for (int i = 1; i*i <= sum; i++) {
    if (sum%i == 0) {
      candidates.insert(i);
      candidates.insert(sum/i);
    }
  }
  ll ans = 1;
  for (ll x : candidates) {
    ll need;
    { // calc need
      vector<ll> r(n);
      for(int i = 0; i < n; i++) {
        r[i] = a[i]%x;
      }
      sort(r.begin(), r.end());
      ll tot = 0;
      for(int i = 0; i < n; i++) {
        tot += r[i];
      }
      int l = n-tot/x;
      need = 0;
      for(int i = 0; i < l; i++) {
        need += r[i];
      }
    }
    if (need <= k) ans = max(ans, x);
  }
  cout << ans << endl;
  return 0;
}