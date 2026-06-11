#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
const ll MOD=1000000007;



int main() {
  int k,q;
  cin>>k>>q;
  vector<ll> d(k),D(k);
  rep(i,k){
      cin>>d.at(i);
  }
  rep(i,q){
      ll n,x,m;
      cin>>n>>x>>m;
      ll ans=n-1;
      rep(j,k){
          D.at(j)=d.at(j)%m;
      }
      ll count0=0;
      rep(j,k){
          if(D.at(j)==0){count0++;}
      }
      count0*=(n-1)/k;
      rep(j,(n-1)%k){
          if(D.at(j)==0){count0++;}
      }
      ans-=count0;

      ll up=0;
      rep(j,k){
          up+=D.at(j);
      }
      up*=(n-1)/k;
      rep(j,(n-1)%k){
          up+=D.at(j);
      }
      up+=x%m;
      ans-=up/m;
      cout<<ans<<endl;
  }
}