#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;
typedef pair<ll,ll> P;

int main(){
  int n;
  cin >> n;
  ll x[n], y[n];
  rep(i,n) cin >> x[i] >> y[i];
  map<P,int> m;
  rep(i,n) {
    rep(j,n) {
      if(i != j) m[P(x[i]-x[j],y[i]-y[j])]++;
    }
  }
  int ans = 0;
  for(auto k : m) ans = max(k.second,ans);
  cout << n - ans << endl;
  return 0;
}