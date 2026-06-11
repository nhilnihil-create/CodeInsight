#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <complex>
#include <deque>
#include <iterator>
#include <numeric>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <limits>
#include <iomanip>
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)
template<class T> inline bool chmax(T& a, T b) {if (a<b) {a=b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if (a>b) {a=b; return true;} return false;}

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

ll n;
string s;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n;
  cin >> s;
  vll lr(2*n); // 0: White, 1: Black
  ll lc=0;
  REP(i, s.size()) {
    if (i%2==0) {
      if (s[i]=='W') {
        lr[i]=1;
      } else{
        lr[i]=0; lc++;
      }
    } else {
      if (s[i]=='B') {
        lr[i]=1;
      } else {
        lr[i]=0; lc++;
      }
    }
  }
  if (s[0]=='W'||s[2*n-1]=='W'||lc!=n) {cout << 0 << '\n'; return 0;}
  ll ans = 1;
  lc = 0;
  REP(i, lr.size()) {
    if (lr[i]==0) lc++;
    else ans = ans*(lc--)%MOD;
  }
  rep(i, 1, n+1) ans = ans*i%MOD;
  cout << ans << '\n';
  return 0;
}
