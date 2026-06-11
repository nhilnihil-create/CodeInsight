#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  vector<int> p(n);
  rep(i,n) cin >> p[i];

  int mini = p[0], ans = 0;
  rep(i,n) {
    if (p[i] <= mini) ans++;
    mini = min(mini, p[i]);
  }
  cout << ans << endl;
  return 0;
}