#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

int main() {
  ll n,k,q;
  cin >> n >> k >> q;
  vector<ll> cor(n,0);
  rep(i,q){
    ll x;
    cin >> x;
    x--;
    cor[x]++;
  }
  
  rep(i,n){
    cor[i] = k - (q-cor[i]);
  }

  rep(i,n){
    if(cor[i] >= 1){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
  
  return(0);
}