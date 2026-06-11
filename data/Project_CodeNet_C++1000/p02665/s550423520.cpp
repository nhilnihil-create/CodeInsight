#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repI(i, d, n) for (int i = (d); i < (n); ++i)
#define reps1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;
using P = pair<int, int>;
using Pl = pair<ll, ll>;
using M = map<int, int>;
using Ml = map<ll, ll>;
ll const INF = 1ll<<61;
double pi = 3.141592653589793238;

int main() {
  // ifstream in("NOMURA2020/1.txt");
  // cin.rdbuf(in.rdbuf());

  ll n;
  cin >> n;
  vector<ll> a(n+1);
  rep(i, n+1) cin >> a[i];

  vector<ll> node(n+1);

  node[0] = 1;
  if (a[0] > 1) {
    cout << -1 << endl;
    return 0;
  }


  reps1(i, n) {
    node[i] = node[i-1] * 2 - a[i];
    chmin(node[i], INF);
    if (node[i] < 0) {
      cout << -1 << endl;
      return 0;
    }
  }

  bool flag = false;
  reps1(i, n) {
    if (node[i] != 0 && flag) {
      cout << -1 << endl;
      return 0;
    }
    if (node[i] == 0) flag = true;
  }


  flag = false;
  if (a[0] != 0) flag = true;
  reps1(i, n+1) {
    if (a[i] != 0 && flag) {
      cout << -1 << endl;
      return 0;
    }
  }
  // rep(i, n) {
  //   cout << i << " " << node[i] << endl;
  // }
  // cout << "a" << endl;
  // cout << node[n-1] << " " << a[n] << endl;
  node[n] = 0;
  if (a[n] > 2 * node[n-1]) {
    cout << -1 << endl;
    return 0;
  }
  //cout << "a" << endl;
  /*
  rep(i, n+1) {
  cout << node[i] << endl;
}
*/

for(ll i = n-1; i >= 0; i--) {
  if (node[i] > node[i+1] + a[i+1]) {
    node[i] = node[i+1] + a[i+1];
  }
  //cout << i << " " << node[i] << endl;
  /*
  if (node[i+1] > node[i] * 2) {
  cout << -1 << endl;
  return 0;
}
*/


}
// ll ans = 0;
// rep(i, n+1) cout << node[i] << " ";
// cout << endl;
/*
rep(i, n) {
  ans += node[i];
  cout << i << " " << ans << endl;
}
*/

cout << accumulate(node.begin(), node.end(), 0ll) + accumulate(a.begin(), a.end(), 0ll) << endl;

return 0;
}
