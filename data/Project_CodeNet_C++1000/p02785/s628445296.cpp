#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  int n,k;
  cin >> n >> k;
  vector<ll> h(n);

  rep(i,n) cin >> h[i];

  sort(h.begin(),h.end());

  ll ans = 0;

  for (int i = 0; i < n-k; i++) {
    ans += h[i];
  }

  cout << ans << endl;

}
