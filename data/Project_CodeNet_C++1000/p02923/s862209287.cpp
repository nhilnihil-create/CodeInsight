#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  vector<ll> times(n,0);
  
  for(ll i=n-2;i>=0;i--){
    if(a[i]>=a[i+1]){
      times[i] = times[i+1]+1;
    }else{
      times[i] = 0;
    }
  }
  
  ll ans=-1;
  rep(i,n){
    ans = max(ans,times[i]);
  }
  
  cout << ans << endl;
  
  return(0);
}