#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <numeric>
#include <cmath>

#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
using P = pair<ll, ll>;

template<class T> inline bool chmin(T& a,T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a,T b) {if (a < b) {a = b; return true;} return false;}

const ll MOD = 1000000007;
const int INF = 1<<30;
//const ll INF = (ll)1e18 + 1;

int main(){
  string s; cin >> s;
  string t; cin >> t;
  int n = s.length(), m = t.length();
  vector<vector<int>> is(26);
  rep(i, n) is[s[i] - 'a'].push_back(i);
  rep(i, n) is[s[i] - 'a'].push_back(i + n);
  ll ans = 0;
  int p = 0;
  rep(i, m){
    int c = t[i] - 'a';
    if (is[c].size() == 0) {cout << -1 << endl; return 0;}
    p = *lower_bound(is[c].begin(), is[c].end(), p) + 1;
    if (p >= n){
      p -= n;
      ans += n;
    }
  }
  ans += p;
  cout << ans << endl;
}
