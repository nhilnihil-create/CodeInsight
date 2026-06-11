#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  const int INF = 100005;
  vector<int> d(INF), arc(INF), abc(INF);
  rep(i,n) {
    int di; cin >> di;
    d[di]++;
  }
  int ans = 0;
  rep(k,INF) {
    if (k==0) continue;
    abc[k] = abc[k-1] + d[k];
    arc[k] = n - abc[k];
    //printf("%d, %d, %d, %d\n", k, d[k], abc[k], arc[k]);
    if (arc[k] == abc[k]) ans++;
    if (arc[k] < abc[k]) break;
  }
  cout << ans << endl;
  return 0;
}