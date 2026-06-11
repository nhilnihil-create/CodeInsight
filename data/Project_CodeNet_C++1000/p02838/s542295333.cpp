#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;

const ll mod = 1000000007;

ll p(ll x, ll n){
  if(n == 0) return 1;
  if(n == 1) return x%mod;
  if(n%2==1) return (x*p(x,n-1))%mod;
  ll t = p(x,n/2);
  return (t*t)%mod;
}

int main(){
  int n;
  cin >> n;
  vector<pair<ll,ll>> d(61);

  rep(i,n){
    ll a;
    cin >> a;
    rep(j,60){
      if(a&(1ll<<j)) d[j].second++;
      else d[j].first++; 
      }
  }

  ll ans = 0;
  ll fac = 1;
  rep(i,60){
    ll temp =(d[i].first*d[i].second)%mod;
    temp *= p(2,i) % mod;
    ans += temp%mod;
    ans %= mod;
    //fac *= 2;
  }
  cout << ans << endl;
}
