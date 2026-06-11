#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n;
  cin >> n;
  vector<ll> p(n);
  ll mini = n+1;
  
  ll ans=0;
  rep(i, n){
    ll x;
    cin >> x;
    mini = min(mini,x);
    if(x == mini)
      ans++;
  }
  cout << ans << endl;
}