#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

int main(){
  int n;
  cin>>n;
  vector<P> p(n);
  rep(i,n){
    ll x,y;
    cin>>x>>y;
    p[i]=make_pair(x,y);
  }
  sort(p.begin(),p.end());
  map<P,int> mp;
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      ll dx,dy;
      dx=p[j].first-p[i].first;
      if(dx==0) dy=abs(p[j].second-p[i].second);
      else dy=p[j].second-p[i].second;
      mp[make_pair(dx,dy)]++;
    }
  }
  int mi=0;
  for(auto x : mp){
    mi=max(x.second,mi);
  }
  cout<<n-mi<<endl;
}
