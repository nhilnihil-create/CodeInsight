
#include <bits/stdc++.h>  
using namespace std;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
using ll = long long int;

ll l=998244353;

int main() {
  ll n; cin>>n;
  vector<ll> v(100000,0);
  ll d0;
  rep(i,n){
    ll d; cin>>d;
    if(i==0)d0=d;
    v[d]++;
  }
  ll i=100000-1;
  while(v[i]==0){
    v.erase(v.begin()+i);
    i--;
  }
  n=v.size();
  ll ans=1;
  rep(j,n-1){
    rep(k,v[j+1]){
      ans*= v[j];
      ans%=l;
    }
  }
  if(v[0] !=1||d0!=0){ans=0;}
 
  cout<<ans<<endl;
}

