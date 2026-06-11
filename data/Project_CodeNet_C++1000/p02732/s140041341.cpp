#include <bits/stdc++.h>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
using ll = long long;
using d = double;

ll comb2(ll x){
  return x*(x-1)/2;
}

int main(){
  int n;
  cin >>n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  vector<int> c(n);
  rep(i,n){
    --a[i];
    ++c[a[i]];
  }
  ll t=0;
  rep(i,n) t+= comb2(c[i]);
  rep(i,n){
    ll ans=t;
    ans-=comb2(c[a[i]]);
    ans+=comb2(c[a[i]]-1);
    printf("%lld\n",ans);
  }
  return 0;
}
