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
  ll n;
  cin >> n;
  vector<ll> a(n+1);
  rep(i, n+1) cin >> a[i];
  
  vector<ll> node(n+1);
  
  node[0] = 1 - a[0];
  if (node[0] < 0) {
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
  
  node[n] = 0;
  if (a[n] > 2 * node[n-1]) {
    cout << -1 << endl;
    return 0;
  }
  
  for(ll i = n-1; i >= 0; i--) {
    chmin(node[i], node[i+1] + a[i+1]);
  }
  
  cout << accumulate(node.begin(), node.end(), 0ll) + accumulate(a.begin(), a.end(), 0ll) << endl;
  
  return 0;
}
