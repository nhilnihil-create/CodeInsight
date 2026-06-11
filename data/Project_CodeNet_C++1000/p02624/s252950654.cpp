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
  ll n; cin >> n;
  ll ans = 0;
  for(ll i = 1; i <= n; i++){
    ll prc = n/i;
    ans += i*prc*(prc+1)/2;
  }
  cout << ans << endl;
  return 0;
}
