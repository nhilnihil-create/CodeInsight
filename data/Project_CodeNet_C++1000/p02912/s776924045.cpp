#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(ll)n;++i)


int main() {
  ll n,m;cin >> n >> m;
  priority_queue<ll> q;
  rep(i,n){
    ll num;cin >> num;
    q.push(num);
  }

  rep(i,m){
    if( q.top() == 0 ) break;
    ll num = q.top();
    q.pop();
    q.push(num/2);
  }

  ll ans = 0;
  while( !q.empty() ){
    ans += q.top();
    q.pop();
  }
  cout << ans << endl;
  return 0;
}