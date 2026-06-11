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
  string s,t;
  cin >> s >> t;
  int n = s.size(), m = t.size();

  vector<vector<int>> vs(26);
  rep(i,n) vs[s[i]-'a'].push_back(i);
  rep(i,n) vs[s[i]-'a'].push_back(i+n);
  
  ll ans = 0, idx = 0;
  rep(i,m){
    int c = t[i]-'a';
    if(vs[c].size() == 0){
      cout << -1 << endl;
      return 0;
    }
    idx = *lower_bound(vs[c].begin(),vs[c].end(),idx) + 1;
    if(idx>=n){
      idx -= n;
      ans += n;
    }
  }
  ans += idx;
  cout << ans << endl;
}
