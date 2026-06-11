#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  vector<int> h(n);
  string ans = "Yes";
  rep(i,n) {
    cin >> h[i];
  }
  int t = -1;
  rep(i,n-1) {
    int d = h[i] - h[i+1];
    if (d <= 1) {
     if (h[i] > t) h[i]--;
    }
    if (h[i] > h[i+1]) {ans = "No"; break;}
    t = max(t,h[i]);
  }
  cout << ans << endl;
  return 0;
}