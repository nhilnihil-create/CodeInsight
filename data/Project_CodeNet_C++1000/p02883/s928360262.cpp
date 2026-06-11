#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i=0; i<(n); ++i)
typedef long long ll;
bool debug=false;
string yes = "Yes";
string no = "No";
ll mod = 1000000007;

int main(){
  ll n,k; cin >> n >> k;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<ll> f(n);
  rep(i,n){
    cin >> f[i];
  }
  sort(f.begin(),f.end(),greater<ll>());
  vector<vector<ll>> q;
  ll ub = 0;
  rep(i,n){
    vector<ll> v(3);
    v[0]=a[i]*f[i]; v[1]=a[i]; v[2]=f[i];
    q.push_back(v);
    ub = max(ub,v[0]);
  }
  ll lb = -1;
  while(ub-lb>1){
    ll mid = (ub+lb)/2;
    ll cnt = k;
    for(auto e:q){
      ll dif = e[1]-(mid/e[2]);
      if(dif<=0) continue;
      cnt -= dif;
    }
    if(cnt>=0){
      ub = mid;
    }else{
      lb = mid;
    }
  }
  cout << ub;
  return 0;
}