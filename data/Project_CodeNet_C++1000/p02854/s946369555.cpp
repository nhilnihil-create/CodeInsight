#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

ll n, p, q;

int main() {
  cin >> n;
  vector<ll> a(n);
  vector<ll> s(n);
  rep (i, n) {
    cin >> a[i];
    a[i] *= 2;
  }
  rep (i, n) {
    s[i] += a[i];
    if (i != 0) s[i] += s[i-1];
  }
  auto itr = lower_bound(s.begin(), s.end(), s[n-1]/2);
  p = *itr;
  if (itr != s.begin()) --itr;
  q = *itr;
  cout << min(p- s[n-1]/2, s[n-1]/2 - q) << endl;
  return 0;
}
