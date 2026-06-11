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
int main(){
  ll n; cin >> n;
  vector<ll> v(n);
  rep(i,n){
    cin >> v[i];
  }
  ll ans=0;
  for(ll i=1;i<n-1;i++){
    ll s = min(v[i-1],min(v[i],v[i+1]));
    ll t = max(v[i-1],max(v[i],v[i+1]));
    if(v[i]!=s&&v[i]!=t) ans++;
  }
  cout << ans;
  return 0;
}
