#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main() {
  double n; cin >> n;
  cout << fixed << setprecision(10);
  vector<pair<double,double>> p(n);
  vector<int> v(n);
  rep(i,n) {
    double x, y; cin >> x >> y;
    p[i] = make_pair(x,y);
    v[i] = i;
  }
  double ans = 0.0;
  int cnt=0;
  do {
    cnt++;
    rep(i,n-1) {
      double dx = p[v[i]].first - p[v[i+1]].first;
      double dy = p[v[i]].second - p[v[i+1]].second;
      ans += sqrt((dx*dx) + (dy*dy));
    }
  } while (next_permutation(v.begin(),v.end()));
  int f=1;
  for (int i = 2; i<=n; i++) f*=i;
  cout << ans / f << endl;
  return 0;
}