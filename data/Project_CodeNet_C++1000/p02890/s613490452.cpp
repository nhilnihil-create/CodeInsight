#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
#define REP(var, a, b) for (int var = (a); var < (b); var++)
#define rep(var, n) for (int var = 0; var < (n); ++var)
#define ALL(c) (c).begin(), (c).end()
#define rALL(c) (c).rbegin(), (c).rend()
ll MOD = 1000000007;
const ll INF = 1LL << 62;

int main() {
  //
  ll n;
  cin >> n;
  map<ll, ll> mp;
  rep(i, n) {
    ll a;
    cin >> a;
    if (mp.find(a) == mp.end()) {
      mp[a] = 1;
    } else {
      mp[a]++;
    }
  }
  vl b;
  for (auto& x : mp) {
    b.push_back(x.second);
  }
  sort(ALL(b));
  vl s(b.size(), 0);
  s[0] = b[0];
  REP(i, 1, s.size()) {
    s[i] = s[i - 1] + b[i];
    // cerr << b[i] << "," <<s[i] << endl;
  }
  REP(k,1,n+1) {
    ll m = 0;
    ll M = s[s.size()-1] / k + 1;
    while (M - m > 1) {
      ll mid = (m + M) / 2;
      // OK?
      // cerr <<"#"<< k << ":" << m << M << endl;
      vl::iterator it = upper_bound(ALL(b), mid);
      int i = it - b.begin();
      ll bsum = 0;
      if (i > 0) {
        bsum += s[i-1];
      }
      bsum += mid * (b.size() - i);
      // cerr << "!"<<i << "," << bsum << endl;
      if (bsum >= mid * k) {
        m = mid;
      } else {
        M = mid;
      }
    }
    cout << m << endl;
  }
  return 0;
}
