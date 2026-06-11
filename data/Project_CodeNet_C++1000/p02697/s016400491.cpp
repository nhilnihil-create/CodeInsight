#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
struct edge { ll s, t, x; };
typedef pair<ll, ll> P;
typedef pair<ll,P> event;
const ll MAX = 510000;
const ll MOD = 1000000007;

int main() {
  ll n,m;cin>>n>>m;
  queue<P>qu;
  if(n%2==1){
    rep(i,m){
      qu.push(P(n-i,2ll+i));
    }
  }
  if(n%2==0){
    rep(i,m){
      ll r=2ll+i;
      ll l=n-i;
      if(l-r>n/2){qu.push(P(r,l));}
      else{qu.push(P(r,l-1ll));}
    }
  }
  rep(i,m){
    auto t=qu.front();qu.pop();
    cout<<t.first<<' '<<t.second<<endl;
  }
}