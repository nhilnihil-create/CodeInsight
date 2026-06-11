#include <bits/stdc++.h>
#include <random>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)




using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;
const ll Lmax=ll(1e18);
const ll Nmax=1e9;
const ll INF=1e9;

int main(){
  ll l,r;
  cin>>l>>r;
  if(r-l>2020){
    cout<<0<<endl;
    return 0;
  }

  ll ans=2019;

  for(ll i=l;i<=r;i++){
    for(ll j=l;j<i;j++){
      ans=min(ans,(i*j)%2019);
    }
  }
  cout<<ans<<endl;




}
