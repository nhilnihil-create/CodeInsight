#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<ll>a(n+1);
  rep(i,0,n+1) cin >> a[i];
  vector<P>c(n+1);
  c[n].first = a[n];c[n].second = a[n];
  for(int i = n-1;i >= 0;i--){
    c[i].first = (c[i+1].first+1)/2+a[i];
    c[i].second = c[i+1].second+a[i];
  }
  if(c[0].first > 1){
    cout << -1 << endl;
    return 0;
  }
  ll ans = 1,v = 1;
  rep(i,1,n+1){
    ll t = min(2*v,c[i].second);
    ans += t;
    v = t-a[i];
  }
  cout << ans << endl;
}