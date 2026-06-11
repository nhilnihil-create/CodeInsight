
#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll INF=1e18;


int main() {
  ll h, w, m;
  cin>>h>>w>>m;
  map<P,ll> v;
  vector<ll> H(h,0);
  vector<ll> W(w,0);
  vector<ll> H1;
  vector<ll> W1;

ll maxh=0;
ll maxw=0;
  rep(i,m){
    P temp;

    cin>>temp.first>>temp.second;
    temp.first--;
    temp.second--;
    v[temp]++;
    H[temp.first]++;
    W[temp.second]++;
    maxh=max(maxh,H[temp.first]);
    maxw=max(maxw,W[temp.second]);
  }
  rep(i,h){
    if (H[i]==maxh){
  //    cout<<i<<endl;
      H1.push_back(i);
    }
  }
  rep(i,w){
    if (W[i]==maxw){
      W1.push_back(i);
    //  cout<<i<<endl;

    }
  }
  ll ans=maxh+maxw;
//  cout<<maxh<<' '<<maxw<<endl;

  ll t=-1;
  if(H1.size()*W1.size()>m){
    cout<<ans;
    return 0;
  }
  for(ll i:H1)for(ll j:W1){

  //  cout<<i<<' '<<j<<endl;
    if (v[make_pair(i,j)]<=0){
      t=0;
    }
  }
  ans+=t;
  cout<<ans;

}
