
#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll INF=1e18;


int main() {
  ll n;
  cin>>n;
  vector<ll> a(n);
  vector<ll> b(n,0);

  rep(i,n)cin>>a[i];
  ll cnt=0;
  for(ll i=n-1;i>=0;i--){
    ll now=i;
    ll s=0;
    while(now<=n-1){
      s+=b[now];
      now+=(i+1);
    }
    if ((s+a[i])%2==1){
      b[i]=1;cnt++;
    }
  }
  cout<<cnt<<endl;
  rep(i,n){
    if (b[i]==1){
      cout<<i+1<<endl;
    }
  }

}
