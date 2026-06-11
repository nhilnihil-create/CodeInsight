#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)
using P = pair<ll,ll>;

int main(){
  ll k;cin >> k;
  queue<ll> q;
  for(ll i=1;i<10;++i) q.push(i);
  rep(i,k-1){
    ll p = q.front();q.pop();
    if( p%10 != 0 ) q.push( p*10 + p%10 -1 );
    q.push( p*10 + p%10 );
    if( p%10 != 9 ) q.push( p*10 + p%10 + 1 );
  }
  cout << q.front() << endl;
  return 0;
}