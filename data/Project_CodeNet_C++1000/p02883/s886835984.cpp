#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

ll n, k;
ll a[220000], f[220000];

ll binary_search(ll k)
{
  ll l = 0, r = 1e12, mid;  
  while (l < r) {
    mid = (l + r) / 2;
    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
      cnt += (max(0LL, a[i] * f[i] - mid) + f[i] - 1) / f[i];
    }
    if (cnt <= k) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return l;
}

int main() {
  cin >> n >> k;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (ll i = 0; i < n; i++) {
    cin >> f[i];
  }
  sort(a, a+n);
  sort(f, f+n, greater<ll>());
  
  cout << binary_search(k) << endl;
  return 0;
}