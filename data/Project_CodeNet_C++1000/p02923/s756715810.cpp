#include<bits/stdc++.h>
#define rep(i,n) for (ll i=0; i<(n); i++)
using namespace std;
using ll = long long;
using vl = vector<ll>;

int main() {
  ll n;
  cin >> n;
  vl h(n);
  rep(i,n) cin >> h[i];
  ll ans = 0, cnt = 0;
  rep(i,n-1) {
    if (h[i] >= h[i+1]) cnt++;
    else cnt = 0;
    ans = max(ans, cnt);
  }
  cout << ans << endl;
}