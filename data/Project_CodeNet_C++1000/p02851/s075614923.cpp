#include <bits/stdc++.h>
#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set

using namespace std;

const ll MOD = 1000000007;

int main() {
  ll n, k;
  scanf("%lld %lld", &n, &k);

  vector<ll> a(n);
  for (ll i = 0; i < n; i++) {
    ll v;
    scanf("%lld", &v);
    a[i] = v;
  }

  vector<ll> csum(a.size() + 1);
  for (ll i = 1; i < a.size() + 1; i++) {
    csum[i] = csum[i - 1] + a[i - 1];
  }

  // cout << m[0] << endl;

  map<ll, ll> m;

  ll ans = 0;
  for (ll i = 0; i <= n; i++) {
    if (i >= k) {
      ll p = i - k;
      ll pdf = csum[p] - p;
      pdf = ((pdf % k) + k) % k;
      m[pdf]--;
    }

    ll df = csum[i] - i;
    df = ((df % k) + k) % k;

    ll plus = m[df];
    // cout << "df:" << df << ", plus:" << plus << endl;
    ans += plus;
    m[df] += 1;
  }

  cout << ans << endl;
}
