#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  int n;
  cin >> n;
  vector<P> v(n);
  map<P,int> seen;
  rep(i,n)cin >> v[i].first >> v[i].second,seen[v[i]] = 1;
  map<P,int> mp;
  rep(i,n){
    for(ll j = i+1;j < n;j++){
      mp[make_pair(v[i].first-v[j].first,v[i].second-v[j].second)]++;
      mp[make_pair(v[j].first-v[i].first,v[j].second-v[i].second)]++;
    }
  }
  pair<ll,ll> k;int cnt = 0;
  for(auto au : mp)if(au.second > cnt)k = au.first,cnt = au.second;
  ll res = 0;
  rep(i,n){
    P ov = v[i];
    if(seen[ov] != 1)continue;
    seen[ov] = 2;
    res++;
    for(ll j = 1;;j++){
      pair<ll,ll> nv = make_pair(ov.first+k.first*j,ov.second+k.second*j);
      if(seen[nv] == 1)seen[nv] = 2;
      else break;
    }
    for(ll j = 1;;j++){
      pair<ll,ll> nv = make_pair(ov.first-k.first*j,ov.second-k.second*j);
      if(seen[nv] == 1)seen[nv] = 2;
      else break;
    }
  }
  cout << res << endl;



  return 0;
}