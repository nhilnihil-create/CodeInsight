#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// totalの約数、それぞれのmod

vector<ll> MakeDivisors(ll n) {
  vector<ll> ret;
  for(ll i = 1; i * i <= n; i++) {
    if(n%i == 0) {
      ret.push_back(i);
      if(i*i != n) ret.push_back(n/i);
    }
  }
  sort(ret.rbegin(), ret.rend());
  return ret;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  ll total = accumulate(a.begin(), a.end(), 0);
  vector<ll> divs = MakeDivisors(total);
  ll ans = 1;
  for (ll d : divs) {
    vector<ll> b(n);
    rep(i, n) b[i] = a[i] % d;
    sort(b.begin(), b.end());
    vector<ll> c(n);
    rep(i, n) c[i] = d - b[i];
    rep(i, n) {
      if (i > 0) b[i] += b[i-1];
    }
    rep(i, n) {
      if (i > 0) c[i] += c[i-1];
    }
    rep(i, n) {
      ll x = b[i];
      ll y = c[n-1] - c[i];
      if (x > k) break;
      if (y > k) continue;
      if ((x+y) / 2 <= k) {
        ans = d;
        goto OUT;
      }
    }
  }
  OUT:
  cout << ans << '\n';
  return 0;
}