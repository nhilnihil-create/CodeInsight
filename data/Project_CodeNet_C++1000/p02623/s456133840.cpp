#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) { a = b; return 1; }
  return 0; }
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) { a = b; return 1; }
  return 0; }
ll MOD = 1000000007;

int main(void){
  ll n,m,k; cin >> n >> m >> k;
  ll a[n],b[m];
  vector<ll> A;
  vector<ll> B;
  A.push_back(0);
  B.push_back(0);
  rep(i,n){
    cin >> a[i];
    A.push_back(A.at(i)+a[i]);
  }
  rep(i,m){
    cin >> b[i];
    B.push_back(B.at(i)+b[i]);
  }
  ll best = m;
  ll ans = 0;
  for(ll i = 0; i <= n; i++){
    ll prc = k-A.at(i);
    if(prc < 0) break;
    while(1){
      if(prc >= B.at(best)) break;
      best--;
      if(best < 0) break;
    }
    ans = max(ans,i+best);
  }
  cout << ans << endl;
  return 0;
}
