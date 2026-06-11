#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pii = pair<int, int>;
#define rep(i,n) for(ll i=0; i<(ll)(n); i++)

int main() {
  ll n,m;  cin>>n>>m;
  vector<ll> v(n);
  ll sum=0;
  rep(i,n){
    cin>>v[i];
    sum+=v[i];
  }
  vector<ll> vec;
  rep(i,n){
    while(v[i]>0){
      vec.push_back(v[i]-v[i]/2);
      v[i]/=2;
    }
  }
  sort(vec.begin(), vec.end(), greater<ll>());

  if(vec.size()<=m){cout<<0;}
  else{
    ll x=0;
    rep(i,m){x+=vec[i];}
    cout<<sum-x;
  }
}

