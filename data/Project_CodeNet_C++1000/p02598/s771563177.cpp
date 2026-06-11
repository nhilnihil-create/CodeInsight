#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

int main() {
  ll n,k;
  cin >> n >> k;
  vector<ll> a(n);
  ll upper=0,lower=0;
  rep(i,n){
    cin >> a[i];
    upper = max(upper,a[i]);
  }
  
  if(k == 0){
    cout << upper << endl;
    return(0);
  }
  
  ll len=ceil((upper+lower)*1.0/2);
  while(upper - lower > 1){
    ll times=0;
    rep(i,n) times += (ceil(a[i]*1.0/len)-1);
    //cout << times << endl;
    if(times <= k){
      upper = len;
    }else{
      lower = len;
    }
    //cout << upper << " " << lower << endl;
    len=ceil((upper+lower)*1.0/2);
  }
  cout << (ll)(ceil(len)) << endl;
  
  return(0);
}