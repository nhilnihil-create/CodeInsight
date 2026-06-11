#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  ll n, k;
  cin >> n >> k;
  ll a[n];
  ll sum = 0;
  rep(i,n) {
    cin >> a[i];
    sum += a[i];
  }
  vector<ll> val;
  for(ll i = 1; i*i <= sum; i++) {
    if(sum % i == 0) {
      val.push_back(i);
      val.push_back(sum/i);
    }
  }
  ll ans = 1;
  for(ll x : val) {
    vector<int> mod(n);
    rep(i,n) mod[i] = a[i] % x;
    sort(mod.begin(),mod.end());
    vector<int> s(n);
    rep(i,n) {
      s[i] += x - mod[i];
      if(i > 0) s[i] += s[i-1];
    }
    ll res = 0;
    rep(i,n) {
      res += mod[i];
      if(res == s[n-1] - s[i]) break;
    }
    if(res <= k) ans = max(ans,x);
  }
  cout << ans << endl;
  return 0;
}
