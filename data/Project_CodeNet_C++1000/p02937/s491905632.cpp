#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
//#include "cxx-prettyprint/prettyprint.hpp"
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repR(i, n) for(int i = (n) - 1; i > -1; i--)
#define rep1(i, n) for(int i = 1; i < (int)(n + 1); i++)
#define rep1R(i, n) for(int i = (n); i > 0; i--)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  vector<set<int>> pos(26);
  rep(i, s.size()) {
    pos.at(s[i] - 'a').insert(i);
  }
  rep(i, t.size()) {
    if (pos.at(t[i] - 'a').lower_bound(0) == pos.at(t[i] - 'a').end()) {
      cout << "-1" << endl;
      return 0;
    }
  }
  ll cur = -1;
  ll ans = 0;
  rep(i, t.size()) {
    auto it = pos.at(t[i] - 'a').lower_bound(cur+1);
    if (it == pos.at(t[i] - 'a').end()) {
      cur = *pos.at(t[i] - 'a').lower_bound(0);
      ans += s.size();
    } else {
      cur = *it;
    }
    if (i == t.size() - 1) {
      ans += cur+1;
    }
  }
  cout << ans << endl;
  return 0;
}
