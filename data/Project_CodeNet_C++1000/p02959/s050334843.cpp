#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  ll n; cin >> n;
  vector<ll> A(n+1),B(n);
  rep(i,n+1) cin >> A[i];
  rep(i,n) cin >> B[i];
  
  ll ans = min(A[0], B[0]);
  B[0] = max(B[0]-A[0], (ll)0);
  
  for(ll i=1; i<n; i++){
    ans += min(A[i], B[i-1]);
    A[i] = max(A[i] - B[i-1], (ll)0);
    ans += min(A[i], B[i]);
    B[i] = max(B[i]-A[i], (ll)0);
  }
  ans += min(A[n], B[n-1]);
  
  cout << ans << endl;
}