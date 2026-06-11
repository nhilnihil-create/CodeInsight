#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll mod=1e9+7;

int main() {
  ll n,k;
  cin >> n >> k;
  if(k>(n-1)*(n-2)/2) {
    cout << -1 << endl;
    return 0;
  }
  if(k==0) {
    cout << n*(n-1)/2 << endl;
    for(ll i=1;i<=n;i++) {
      for(ll j=i+1;j<=n;j++) {
        cout << i << " " << j << endl;
      }
    }
    return 0;
  }
  k=(n-1)*(n-2)/2-k;
  cout << n-1+k<< endl;
  for(ll i=1;i<n;i++) {
    cout << 1 << " " << i+1 << endl;
  }
  for(ll i=2;i<=n;i++) {
    for(ll j=i+1;j<=n;j++) {
      if(k>0) {
        cout << i << " " << j << endl;
        k--;
      }
      else {
        break;
      }
    }
  }
}