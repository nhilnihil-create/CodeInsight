#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(n, i) for(ll i = 0; i < n; ++i)

void solve(void){
  ll n, k; cin >> n >> k;
  vector<ll> va(n, 0);
  rep(n, i) cin >> va[i];

  for(ll i = 1; i <= k; ++i) {
    vector<ll> query(n+1, 0);
    rep(n, j) {
      ll l = max(0LL, j-va[j]);
      ll r = min(n-1, j+va[j]);
      ++query[l];
      --query[r+1];
    }
    for(ll j = 1; j < n; ++j) query[j] += query[j-1];

    bool flag = true;
    rep(n, j) {
      if (query[j] != va[j]) flag = false;
    }
    if (flag == true) {
      rep(n, j) {
        cout << query[j];
        (j < n-1) ? cout << " " : cout << endl;
      }
      return;
    }

    rep(n, j) va[j] = query[j];
  }

  rep(n, i) {
    cout << va[i];
    (i < n-1) ? cout << " " : cout << endl;
  }

}

int main(void) {
  solve();
  return 0;
}