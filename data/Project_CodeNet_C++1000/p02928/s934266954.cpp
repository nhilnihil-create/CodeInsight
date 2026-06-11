#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = s; i < (ll)(n); i++)
typedef long long ll;
typedef vector<vector<ll>> vvl;
typedef vector<ll> vl;
typedef vector<vector<char>> vvc;
typedef vector<char> vc;
typedef pair<ll,ll> pll;
ll max(ll x,ll y){
if(x>y)return x;
else return y;
}
ll min(ll x,ll y){
  return x+y-max(x,y);
}


int main() {
  ll n,k;cin >> n >> k;
  vl a(n);
  rep(i,n){
    cin >> a[i];
  }
  ll moremin=0;
  ll cnt=0;
  rep(i,n){
    rep(j,n){
      if(i<j&&a[i]>a[j])cnt++;
      if(a[i]>a[j])moremin++;
    }
  }
  
  ll ans=0;
  ans+=cnt*k%1000000007;
  if(k%2==0)
  ans+=(moremin%1000000007)*((k/2)*(k-1)%1000000007);
  else ans+=(moremin%1000000007)*((k)*((k-1)/2)%1000000007);
  cout << ans%1000000007 << endl;
}