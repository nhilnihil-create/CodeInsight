#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n; cin >> n;
  vector<ll> A(n);
  rep(i,n) cin >> A[i];
  
  sort(A.rbegin(),A.rend());
  ll ans = A[0];
  
  if(n%2==0){
    for(ll i=1; i<n/2; i++){
      ans += A[i]*2;
    }
  }
  if(n%2==1){
    for(ll i=1; i<n/2; i++){
      ans += A[i]*2;
    }
    ans += A[n/2];
  }
  
  cout << ans << endl;
}