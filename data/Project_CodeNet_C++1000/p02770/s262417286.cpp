#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef pair<ll,ll> P;
using VP = vector<P>; using VVP = vector<VP>;
using VI = vector<ll>; using VVI = vector<VI>; using VVVI = vector<VVI>;
const int inf=1e9+7;
const ll INF=1LL<<61;
const ll mod=1e9+7;

template<class T>
inline bool chmax(T &a, T b) {
  if(a < b) {
    a = b;
    return true;
  }
  return false;
}

template<class T>
inline bool chmin(T &a, T b) {
  if(a > b) {
    a = b;
    return true;
  }
  return false;
}

int main(){
  int i,j;
  ll k,q;
  cin>>k>>q;
  ll d[k];
  ll sum=0;
  for(i=0;i<k;i++) {
    cin>>d[i];
  }
  while(q--){
    ll n,x,m;
    cin>>n>>x>>m;
    n--;
    ll dd[k];
    ll z=0;
    ll sum=0;
    for(i=0;i<k;i++) {
      dd[i]=d[i]%m;
      sum+=dd[i];
      if(dd[i]==0) z++;
    }
    ll nn=n%k;
    ll loop=(n-nn)/k;
    ll cnt=0;
    for(i=0;i<nn;i++){
      if(x%m>=(x+dd[i])%m) cnt++;
      x+=dd[i];
    }
    cnt+=z*loop;
    cnt+=(x+sum*loop)/m-(x/m);
    cout<<n-cnt<<endl; 
  }
  


}