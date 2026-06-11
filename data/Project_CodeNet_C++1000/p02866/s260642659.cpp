#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i=0; i<(n); ++i)
#define rep1(i,n) for (ll i=1; i<=(n); ++i)
typedef long long ll;
bool debug=false;
string yes = "Yes";
string no = "No";
const ll mod = 998244353;

int main(){
  ll n; cin >> n;
  map<ll,ll> m;
  rep(i,n){
    ll d; cin >> d;
    if(i==0&&d!=0){cout << 0; return 0;}
    if(i!=0&&d==0){cout << 0; return 0;}
    m[d]++;
  }
  if(debug){
    for(auto p:m){
      cout << p.first << ":" << p.second << endl;
    }
  }
  ll ans=1;
  for(ll i=0; i<m.size()-1;i++){
    ll c = m[i];
    ll ne = m[i+1];
    rep(j,ne){
      ans*=(c%mod);
      ans%=mod;
    }
  }
  cout << ans;
  return 0;
}