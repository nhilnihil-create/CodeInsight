#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll n,k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  ll sum = 0;
  rep(i,n) sum += a[i];

  vector<ll> ps;
  for(ll i = 2; i*i<=sum; ++i){
    if(sum%i==0){
      ps.emplace_back(i);
      if(i*i!=sum) ps.emplace_back(sum/i);
    }
  }
  ps.push_back(sum);
  ll ans = 1;
  for(ll p:ps){
    bool ok = [&]{
      vector<ll> m;
      rep(i,n) if(a[i]%p!=0) m.emplace_back(a[i]%p);
      if(m.empty()) return true;
      sort(m.begin(),m.end());

      vector<ll> l(m.size()+1), r(m.size()+1);
      rep(i,m.size()){
        l[i+1] = l[i] + m[i];
        r[i+1] = r[i] + (p-m[m.size()-1-i]);
      }
      rep(i,m.size()+1){
        ll li = l[i], ri = r[m.size()-i];
        if( li>k || ri>k ) continue;
        if(abs(li-ri)%p==0) return true;
      }
      return false;
    }();
    if(ok) ans = max(ans,p);
  }
  cout << ans << endl;
}
