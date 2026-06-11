#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
double ans = 0;
bool arg(pair<ll,ll> a,pair<ll,ll> b,pair<ll,ll> c){
return (b.first-a.first)*(c.second-b.second)-(b.second-a.second)*(c.first-b.first)<0;
}
bool arg2(pair<ll,ll> a,pair<ll,ll> b,pair<ll,ll> c){
return (b.first-a.first)*(c.second-b.second)-(b.second-a.second)*(c.first-b.first)>0;
}

int main()
{
ll n ;
cin >> n ;
set<pair<ll,ll>> s;
s.insert({0,0});
rep(i,n){
  ll x , y ;
  cin >> x >> y ;
  vector<pair<ll,ll>> vs;
  for(auto p:s){
    vs.push_back({x+p.first,y+p.second});
  }
  for(auto p:vs){
    s.insert(p);
  }
  vector<pair<ll,ll>> v;
  for(auto p:s){
    if(v.size()<2)v.push_back(p);
    else{
      while(!arg(v[v.size()-2],v[v.size()-1],p)&&v.size()>=2)v.pop_back();
      v.push_back(p);
    }
  }
  vector<pair<ll,ll>> vv;
    for(auto p:s){
    if(vv.size()<2)vv.push_back(p);
    else{
      while(!arg2(vv[vv.size()-2],vv[vv.size()-1],p)&&vv.size()>=2)vv.pop_back();
      vv.push_back(p);
    }
  }
  s.clear();
  for(auto p:v){
    s.insert(p);
  }
    for(auto p:vv){
    s.insert(p);
  }
}
for(auto p:s){
  ans=max(ans,sqrt(p.first*p.first+p.second*p.second));
}
cout<<fixed<<setprecision(13)<<ans<<endl;
return 0;
}
