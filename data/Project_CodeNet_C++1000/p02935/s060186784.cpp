#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n; cin >> n;
  vector<ll> v(n);
  rep(i,n) cin >> v[i];
  sort(v.begin(), v.end());
  double ans = v[0];
  
  for(ll i=1; i<n; i++){
    ans += v[i];
    ans /= 2;
  }
  cout << fixed << setprecision(7);
  cout << ans << endl;
}