#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n,x; cin >> n >> x;
  vector<ll> v(n);
  rep(i, n)
    cin >> v[i];
  
  ll cnt = 1;
  ll sum = 0;
  
  rep(i, n){
    sum += v[i];
    if(sum <= x)
      cnt ++;
    else
      break;
  }
  cout << cnt << endl;
}