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

  int n = s.size();
  s += s;
  vector<int> vs[26];
  rep(i,s.size()) vs[s[i]-'a'].push_back(i);
  
  ll ans = 0; int idx = -1;
  rep(i,t.size()){
    int c = t[i]-'a';
    if(vs[c].empty()){
      cout << -1 << endl;
      return 0;
    }
    idx = *upper_bound(vs[c].begin(),vs[c].end(),idx);
    if(idx>=n){
      idx -= n;
      ans += n;
    }
  }
  ans += idx + 1;
  cout << ans << endl;
}
