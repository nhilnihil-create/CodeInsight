#include<bits/stdc++.h>
using namespace std;
using ll=long long;


int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  ll ans=1000;
  for(int i=0;i<n;++i) cin >> a[i];

  for(int i=0;i<n-1;++i){
    ll s=0;
    if(a[i]<a[i+1]) s=ans/a[i];
    ans+=(a[i+1]-a[i])*s;
  }
  cout << ans << endl;
  return 0;
}
