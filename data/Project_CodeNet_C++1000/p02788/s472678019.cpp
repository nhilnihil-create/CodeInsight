#include<bits/stdc++.h>
using namespace std;
using ll=long long;


int main(){
  ll n,d,a;
  cin >> n >> d >> a;
  vector<pair<ll,ll>> xh(n);
  for(ll i=0;i<n;++i){
    ll x,h;
    cin >> x >> h;
    xh[i]=make_pair(x,h);
  }

  sort(xh.begin(),xh.end());
  d=d*2;
  ll ans=0;
  ll tot=0;
  queue<pair<ll,ll>> q;
  for(ll i=0;i<n;++i){
    ll x=xh[i].first;
    ll h=xh[i].second;
    while(q.size()!=0 && q.front().first<x){
      tot-=q.front().second;
      q.pop();
    }
    h-=tot;
    if(h>0){
      ll num=(h+a-1)/a;
      ll damage=num*a;
      ans+=num;
      tot+=damage;
      q.push(make_pair(x+d,damage));
    }
  }

  cout << ans << endl;
  return 0;

}
