#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
using ll = long long;

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> h(n);
  rep(i, n) cin >> h[i];
  sort(h.begin(), h.end());
  reverse(h.begin(), h.end());
  ll sum = 0;
  for(int i = k; i < n; i++) sum += h[i];
  cout << sum << endl;
}
