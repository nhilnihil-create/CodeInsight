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

ll INF = 1000000007;

int main(void){
  ll n; cin >> n;
  ll a[n];
  rep(i,n) cin >> a[i];
  vector<ll> one(60,0);
  vector<ll> zero(60,0);
  for(int i = 0; i < n; i++){
    for(int j = 0; j <= 60; j++){
      if(a[i] >> j & 1LL) one[j]++;
      else zero[j]++;
    }
  }
  ll ans = 0;
  ll via = 1;
  for(int i = 0; i <= 60; i++){
    ans += (one[i]*zero[i])%INF*via%INF;
    via = via*2%INF;
  }
  cout << ans%INF << endl;
  return 0;
}
