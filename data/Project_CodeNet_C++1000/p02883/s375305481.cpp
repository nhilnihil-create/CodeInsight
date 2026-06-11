#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  ll n,K;
  cin >> n >> K;
  vector<ll> a(n),f(n);
  rep(i,n)cin >> a[i];
  rep(i,n)cin >> f[i];
  sort(ALL(a));
  sort(ALL(f),greater<ll>());
  vector<pair<ll,ll>> v(n);
  rep(i,n)v[i] = make_pair(a[i],f[i]);
  ll left = -1,right = 1e13;
  while(right-left > 1){
    ll mid = (right+left)/2;
    ll k = K;
    rep(i,n){
      if(v[i].second*v[i].first <= mid)continue;
      k -= (v[i].first - mid/v[i].second);
    }
    if(k >= 0)right = mid;
    else left = mid;
  }
  cout << right << endl;




  return 0;
}