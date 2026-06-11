#include<bits/stdc++.h>
using namespace std;
using ll=long long;


const int MOD=1e9+7;



int main(){
  int n;
  cin >> n;
  vector<ll> z(n),w(n);
  for(int i=0;i<n;++i){
    ll x,y;
    cin >> x >> y;
    z[i]=x+y;
    w[i]=x-y;
  }
  ll zma,zmi,wma,wmi;
  zma=z[0];
  zmi=z[0];
  wma=w[0];
  wmi=w[0];
  for(int i=0;i<n;++i){
    zma=max(zma,z[i]);
    zmi=min(zmi,z[i]);
    wma=max(wma,w[i]);
    wmi=min(wmi,w[i]);
  }
  ll ans=max(zma-zmi,wma-wmi);
  cout << ans << endl;
  return 0;
}
