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
  int n;
  cin >> n;
  vector<int> idx(n);
  rep(i,n){
    int p;
    cin >> p;
    idx[p-1] = i;
  }

  ll ans = 0;
  set<int> s;
  for(int x = n-1; x>=0; --x){
    int i = idx[x];
    vector<ll> l(2,-1), r(2,n);

    s.insert(i);
    auto itrl = s.find(i);
    auto itrr = itrl;
    rep(ii,2){
      if(itrl==s.begin()) break;
      --itrl;
      l[ii] = *itrl;
    }
    rep(ii,2){
      ++itrr;
      if(itrr==s.end()) break;
      r[ii] = *itrr;
    }
    ans += (x+1)*((i-l[0])*(r[1]-r[0])+(l[0]-l[1])*(r[0]-i));
  }
  cout << ans << endl;
}
