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
#include <bitset>

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
  int N; cin >> N;
  vector<ll> a(N + 1);
  ll S = 0;
  rep(i, N + 1) {
    cin >> a[i];
    S += a[i];
  }

  ll ans = 0;
  ll f = 1;
  for (int i = 0; i <= N; ++i){
    ans += f;
    if (f < a[i]){
      cout << -1 << endl;
      return 0;
    }
    f -= a[i];
    S -= a[i];
    f *= 2;
    f = min(f, S);
  }
  cout << ans << endl;
  return 0;
}
