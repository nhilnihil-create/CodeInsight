#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

vector<P>Div(ll n){
  vector<P> d;
  for(ll i = 2; i*i <= n; i++){
    ll cnt = 0;
    while(n % i == 0){
      n /= i;
      cnt++;
    }
    d.push_back(P(i,cnt));
  }
  if(n != 1) d.push_back(P(n,1));
  return d;
}

int main(void){
  ll n;
  cin >> n;
  vector<P> d = Div(n);
  ll ans = 0;
  for(ll i = 0; i < d.size(); i++){
    for(ll j = 1; j <= d[i].second; j++){
      ll tmp = pow(d[i].first,j);
      if(n % tmp != 0) continue;
      n /= tmp;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}