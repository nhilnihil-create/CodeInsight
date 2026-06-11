#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll mod=1e9+7;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(ll i=0;i<n;i++) {
    cin >> a[i];
  }
  vector<ll> c(3);
  ll ans=1;
  for(ll i=0;i<n;i++) {
    if(i==0) {
      if(a[i]!=0) {
        ans=0;
      }
      else {
        ans*=3;
        c[0]++;
      }
    }
    else {
      ll temp=0;
      for(ll j=0;j<3;j++) {
        if(c[j]==a[i]) {
          if(temp==0) {
            c[j]++;
          }
          temp++;
        }
      }
      ans=(ans*temp)%mod;
    }
  }
  cout << ans << endl;
}