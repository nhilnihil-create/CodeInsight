#include <bits/stdc++.h>  
using namespace std;
using ll = long long int;
using pll = pair<long long int,long long int>;
#define rep(i,n) for(ll i=0; i<(ll)(n); i++)

int main() {
  ll n; cin>>n;
  vector<pll> v(n);
  rep(i,n){
    ll a,b; cin>>a>>b;
    v[i].first=a+b;
    v[i].second=a-b;
  }
  sort(v.begin(),v.end());
  ll m=v[0].first;
  ll c=1;
  rep(i,n){
    if(v[i].second>=m){m=v[i].first;c++;}
  }
  cout<<c;
}