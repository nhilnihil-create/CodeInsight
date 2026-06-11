
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> P;
#define rep(i,n) for(ll i=0;i<n;++i)
const ll INF=1e18+1;

int main(){
  ll n,k;
  cin>>n>>k;
  vector<ll> a(n);
  vector<ll> f(n);
  rep(i,n){
    cin>>a[i];
  }
  rep(i,n){
    cin>>f[i];
  }
  sort(a.begin(),a.end());
  sort(f.rbegin(),f.rend());
  ll l,r;
  l=-1;r=1e12;

//  int cnt=INF;
  while (l+1<r){
    ll c=(l+r)/2;
  //  cout<<c<<endl;
    ll cnt=0;
    rep(i,n){
      cnt+=max(0ll,a[i]-c/f[i]);
    }
    if (cnt<=k) r=c;
    else l=c;
  
  //  cout<<c<<' '<<l<<' '<<r<<endl;

  }
  cout<<r;




  }
