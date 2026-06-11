 #include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n;
  cin >> n;
  vector<ll> v(n);
  rep(i, n)
    cin >> v.at(i);
  
  ll k = 1;
  ll ans = 0;
  ll cnt = 0;
  rep(i, n){
    if(v.at(i) == k)
      k++;
    else{
      ans++;
      cnt ++;
    }
  }
  
  if(cnt == n)
    cout << -1 << endl;
  else
    cout << ans << endl;
}