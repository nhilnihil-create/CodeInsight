#include<bits/stdc++.h>
using namespace std;
using ll=long long;

const int MOD=1000000000+7;

int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  for(int i=0;i<n;++i) cin >> a[i];

  ll ans=0;
  ll two=1;
  for(int b=0;b<60;++b){
    ll ones=0;
    ll zero=0;
    for(int i=0;i<n;++i){
      if(a[i] & (1LL<<b)) ones++;
      else zero++;
    }
    ll cal=(ones*zero)%MOD*two%MOD;
    ans=(ans+cal)%MOD;
    two=(two*2)%MOD;
  }
  cout << ans << endl;
  return 0;

}
