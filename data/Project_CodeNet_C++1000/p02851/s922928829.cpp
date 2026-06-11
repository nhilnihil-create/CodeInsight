#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;

int main() {
  ll n,k; cin >> n >> k;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  vector<int> m(n+1);
  rep(i,n) m[i+1] = (m[i]+a[i])%k;
  rep(i,n+1){ m[i] -= i; m[i] %= k; if(m[i] < 0) m[i] += k;}

  ll ans = 0;
  map<int,int> mp;
  int l = 0;
  rep(r,n+1){
    if(r-l+1>k){
      mp[m[l]]--;
      ++l;
    }
    ans += mp[m[r]];
    mp[m[r]]++;
  }
  cout << ans << endl;
}
