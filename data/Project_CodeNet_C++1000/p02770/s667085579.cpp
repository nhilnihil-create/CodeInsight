#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int k,q;
  cin >> k >> q;

  vector<int> d(k);
  rep(i,k) cin >> d[i];

  vector<ll> ans(q);
  rep(qi,q){
    int n,x,m;
    cin >> n >> x >> m;
    ll val = x;
    rep(i,k){
      ll cnt = ((n-1-i) + k - 1) / k;
      val += (d[i]%m) * cnt;
      if ( d[i]%m == 0 ) {
        val += m * cnt;
      }
    }
    ans[qi] = n-1 - (val/m - x/m);
  }
  rep(i,q) cout << ans[i] << endl;
}
