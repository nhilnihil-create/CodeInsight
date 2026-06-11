#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define ll int64_t
#define _GLIBCXX_DEBUG
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int main(){
  int n;
  cin >> n;
  vector<ll> a(n),l(n),f(n),e(n);
  vector<pair<ll,ll>> p(n);
  rep(i,n){
    cin >> a[i] >> l[i];
    f[i]=a[i]-l[i];
    e[i]=a[i]+l[i];
    p[i]=make_pair(e[i],f[i]);
  }
  sort (all(p));
  ll t=-1000000000000;
  int ans;
  rep(i,n){
    if(t<=p[i].second){
      t=p[i].first;
      ans++;
    }
  }
  cout << ans << endl;
}