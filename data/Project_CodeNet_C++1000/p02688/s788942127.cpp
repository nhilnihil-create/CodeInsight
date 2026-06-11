#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n,k;
  cin >> n >> k;
  vector<ll> sun(n);
  rep(i, n)
    sun.at(i) = i;
  
  vector<vector<ll>> safe(k);
  
  rep(i, k){
    ll kosu;
    cin >> kosu;
    
    rep(j, kosu){
      ll name;
      cin >> name;
      safe.at(i).push_back(name-1);
    }
  }
  
  rep(i, k){
    rep(j, safe.at(i).size()){
      rep(m, n){
        if(sun.at(m) == safe.at(i).at(j))
          sun.at(m) = -1;
      }
    }
  }
  
  ll count=0;
  rep(i, n){
    if(sun.at(i) != -1)
      count++;
  }
  cout << count << endl;
}