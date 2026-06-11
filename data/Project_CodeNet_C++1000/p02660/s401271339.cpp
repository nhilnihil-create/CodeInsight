#include<iostream>
#include<vector>
#include<utility>
using namespace std;
using ll = long long;

vector<pair<ll,ll> > primeFactorize(ll x) {
  vector<pair<ll,ll> > res;
  for (ll i=2;i*i<=x;i++) {
    ll ex=0;
    while (x%i == 0) {
      ex++;
      x/=i;
    }
    if (ex>0) res.push_back({i, ex});
  }
  if (x>1) res.push_back({x, 1});

  return res;
}

int main() {
  ll N,i,j,ans=0;
  cin>>N;
  vector<pair<ll,ll> > pF = primeFactorize(N);
  for (i=0;i<pF.size();i++) {
    for (j=1;j<=pF[i].second;j++) {
      pF[i].second -= j;
    }
    ans += (j-1);
  }
  cout<<ans<<endl;
  return 0;
}
