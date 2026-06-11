#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  vector<P> D(n);
  rep(i,n) {
    int d1, d2; cin >> d1 >> d2;
    D[i] = make_pair(d1,d2);
  }
  string ans = "No";
  rep(i,n) {
    int cnt = 0;
    while (i < n && D[i].first == D[i].second) {
      i++;
      cnt++;
    }
    if (cnt >= 3) {
      ans = "Yes";
      break;
    }
  }
  cout << ans << endl;
  return 0;
}