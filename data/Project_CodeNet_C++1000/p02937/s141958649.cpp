#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const ll M = 1e9+7;
const ll INF = 1e9+7;

string s, t;
ll m, n;
vector<ll> c_id[30];
ll ans;

void binary_search(ll c) {
  ll l = 0, r = c_id[c].size(), mid;
  if (r == 0) {
    cout << -1 << endl;
    exit(0);
  }
  while (l < r) {
    mid = (l + r) / 2;
    if (c_id[c][mid] >= ans%m)
      r = mid;
    else
      l = mid + 1;
  }
  if (l != c_id[c].size()) ans = ans/m*m + c_id[c][l]+1;
  else ans = ans/m*m+m + c_id[c][0]+1;
}

int main() {
  cin >> s >> t;
  m = s.length();
  n = t.length();
  
  for (ll i = 0; i < m; i++) {
    c_id[s[i]-'a'].push_back(i);
  }
  
  for (ll i = 0; i < n; i++) {
    binary_search(t[i]-'a');
  }
  
  cout << ans << endl;
  return 0;
}