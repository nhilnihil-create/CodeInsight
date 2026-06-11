#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n; cin >> n;
  vector<ll> B(n-1);
  rep(i, n-1) cin >> B[i];
  
  ll ans = B[0] + B[n-2];
  rep(i, n-2)
    ans += min(B[i], B[i+1]);
  
  cout << ans << endl;
}