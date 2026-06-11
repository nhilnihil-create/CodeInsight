#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i,n) for (ll i=0; i<(n); ++i)
#define rep1(i,n) for (ll i=1; i<=(n); ++i)
typedef long long ll;
bool debug=false;
string yes = "Yes";
string no = "No";
const ll mod = 998244353;
const double e = 0.000000001;
ll dp[105][2][5];
double dist(vector<ll> v1,vector<ll> v2){
  double ans=0;
  rep(i,v1.size()){
    ans+=(v1[i]-v2[i])*(v1[i]-v2[i]);
  }
  ans = sqrt(ans);
  return ans;
}
int main(){
  ll n; cin >> n;
  ll d; cin >> d;
  vector<vector<ll>> vs;
  rep(i,n){
    vector<ll> v(d);
    rep(i,d){
      cin >> v[i];
    }
    vs.push_back(v);
  }
  ll ans=0;
  rep(i,n){
    for(ll j=i+1;j<n;j++){
      double p = dist(vs[i],vs[j]);
      if(p==ceil(p)) ans++;
    }
  }
  cout << ans;
  return 0;
}
