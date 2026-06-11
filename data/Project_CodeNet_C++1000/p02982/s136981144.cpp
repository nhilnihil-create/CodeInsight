#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  ll n,d;
  cin >> n >> d;
  vector<vector<ll>> v(n, vector<ll>(d));
  
  rep(i,n){
    rep(j,d)
      cin >> v.at(i).at(j);
  }
  ll ans = 0;
  
  rep(i,n){
    for(ll j=i+1; j<n; j++){
      ll dis = 0;
      rep(k, d)
        dis += (v.at(i).at(k)-v.at(j).at(k))*(v.at(i).at(k)-v.at(j).at(k));
      
      rep(l, 200000){
        if(dis == l*l)
          ans++;
      }
    }
  }
  
  cout << ans << endl;
}