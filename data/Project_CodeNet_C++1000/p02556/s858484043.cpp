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

const int inf = 1001001001;
int main() {
  int n;
  cin >> n;
  vector<int> x(n),y(n);
  rep(i,n) cin >> x[i] >> y[i];

  int mi,ma;
  mi = inf, ma = -inf;
  rep(i,n){
    mi = min(mi,x[i]+y[i]);
    ma = max(ma,x[i]+y[i]);
  }
  int ans = ma-mi;
  mi = inf, ma = -inf;
  rep(i,n){
    mi = min(mi,x[i]-y[i]);
    ma = max(ma,x[i]-y[i]);
  }
  ans = max(ans,ma-mi);
  cout << ans << endl;
}
