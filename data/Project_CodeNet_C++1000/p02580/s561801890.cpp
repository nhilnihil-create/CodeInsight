#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

int main() {
  ll h,w,m;
  cin >> h >> w >> m;
  vec y(m),x(m);
  map<ll,ll> cy,cx;
  for(ll i=0;i<m;i++) {
    cin >> y[i] >> x[i];
    cy[y[i]]++;
    cx[x[i]]++;
  }
  ll my=1,mx=1;
  for(auto p:cy) {
    my=max(my,p.second);
  }
  for(auto p:cx) {
    mx=max(mx,p.second);
  }
  set<ll> mylist,mxlist;
  for(auto p:cy) {
    if(my==p.second) {
      mylist.insert(p.first);
    }
  }
  for(auto p:cx) {
    if(mx==p.second) {
      mxlist.insert(p.first);
    }
  }
  ll cnt=0;
  for(ll i=0;i<m;i++) {
    if(mylist.count(y[i])&&mxlist.count(x[i])) {
      cnt++;
    }
  }
  ll ans=mx+my;
  if(cnt==mylist.size()*mxlist.size()) ans--;
  cout << ans << endl;
}
