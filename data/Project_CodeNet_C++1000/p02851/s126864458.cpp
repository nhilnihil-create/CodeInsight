#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll n, k;
  cin >> n >> k;
  
  vector<ll> a(n + 1);
  for(int i = 1; i <= n; i++){
    cin >> a.at(i);
    a.at(i) += a.at(i - 1);
  }
  for(int i = 1; i <= n; i++){
    a.at(i) -= i;
    a.at(i) %= k;
  }
  
  map<ll, ll> mp;
  ll ans = 0;
  for(int i = 0; i <= n; i++){
    if(i < k){
      ans += mp[a.at(i)];
      mp[a.at(i)]++;
    }
    else{
      mp[a.at(i - k)]--;
      ans += mp[a.at(i)];
      mp[a.at(i)]++;
    }
  }
  
  cout << ans << '\n';
}