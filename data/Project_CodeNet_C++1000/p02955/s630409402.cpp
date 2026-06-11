#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int mod = 1000000007;
const ll INF = 1001001001;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
  int n,k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  ll s = 0;
  rep(i,n) s += a[i];
  set<ll> candidates;
  for(ll i=1;i*i<=s;i++){
    if(s%i==0){
      candidates.insert(i);
      candidates.insert(s/i);
    }
  }
  ll ans = 1;
  for(ll x:candidates){
    ll need = INF;
    vector<int> b(n);
    rep(i,n) b[i] = a[i] % x;
    sort(b.begin(),b.end());
    ll r = 0;
    rep(i,n) r += (x-b[i]);
    ll l = 0;
    rep(i,n){
      l += b[i];
      r -= (x-b[i]);
      need = min(need,max(l,r));
    }
    if(need<=k) ans = max(ans,x);
  }
  cout << ans << endl;
}