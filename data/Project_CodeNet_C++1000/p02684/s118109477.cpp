#include <iostream>
#include <vector>
#include <map>

using ll = long long;
using namespace std;
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int main() {
  ll n,k; cin>>n>>k;
  vector<ll> a(n+1);
  rep(i,n) cin>>a[i+1];
  struct Data{ ll offset; ll cycle;};
  map<ll,Data> m;

  ll now = 1;
  for(ll i=0; i<k; i++){
    if(m.count(now) == 0){
      m[now].offset = i;
    }else{
      m[now].cycle = i-m[now].offset;
      break;
    }
    now = a[now];
  }
  
  ll ans = now;
  if(m[now].cycle > 0){
    k-=m[now].offset;
    k%=m[now].cycle;
    while(k>0){
      ans=a[ans];
      k--;
    }
  }
  
  
  cout<<ans<<endl;
  return 0;
}