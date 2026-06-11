#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <numeric>
#include <string>
#include <cassert>
#include <bitset>

using namespace std;
typedef long long ll;

int main() {
  string s, t;
  cin >> s >> t;
  map<char, vector<ll> > c2v;
  for (ll i = 0; i < (ll)s.size(); ++i) {
    char c = s[i];
    c2v[c].push_back(i);
  }

  for (auto c : t) {
    if (c2v[c].size() == 0) {
      cout << -1 << endl;
      return 0;
    }
  }
  
  char c = t[0];
  ll prev = c2v[c][0];
  ll cnt = 0;
  for (ll i = 1; i < (ll)t.size(); ++i) {
    char c = t[i];
    vector<ll> &v = c2v[c];
    auto it = upper_bound(v.begin(), v.end(), prev);
    if (it != v.end()) {
      prev = *it;
    } else {
      ++cnt;
      prev = v[0];
    }
  }

  ll ans = cnt * (ll)s.size() + prev + 1;
  cout << ans << endl;
  
  return 0;
}
