#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

int main(){
  int n;cin>>n;
  vector<pair<ll, ll>> xy;
  rep(i, n){
    int x,y;cin>>x>>y;
    xy.emplace_back(x,y);
  }

  map<pair<ll, ll>, int> logger;
  int maxc=0;
  rep(i, n)rep(j, n){
    if(i==j)continue;
    ll dx = xy[i].first-xy[j].first;
    ll dy = xy[i].second-xy[j].second;
    auto k = make_pair(dx,dy);
    logger[k]++;
    maxc=max(maxc, logger[k]);
//cout<<k.first<<' '<<k.second<<endl;
  }
//cout<<endl;
  cout<<(n-maxc)<<endl;
//cout<<n<<' '<<maxc;

  return 0;
}