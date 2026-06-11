#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
  ll n;
  cin >>n;
  vector<pair<ll,ll>>fac;
  ll ans=0;
  for(ll i=2;i*i<=n;i++){
    if(n%i!=0)continue;
    int ex=0;
    while(n%i==0){
      ex++;
      n/=i;
    }
    fac.push_back({i,ex});
  }
  if(n!=1)fac.push_back({n,1});
  for(auto f:fac){
    int tmp=0;
    int e=1;
    while(f.second>=e){
      f.second-=e;
      e++;
      tmp++;
    }
    ans+=tmp;
  }
  cout <<ans<<endl;
}