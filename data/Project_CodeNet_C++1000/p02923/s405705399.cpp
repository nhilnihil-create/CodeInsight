#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  vector<int> H(n);
  int ans = 0;
  rep(i,n) cin >> H[i];
  rep(i,n-1) {
    if (H[i] < H[i+1]) continue;
    else {
      int cnt = 0;
      while (H[i] >= H[i+1] && i < n-1) {
        cnt++;
        i++;
      }
      ans = max(ans, cnt);
    }
  }
  cout << ans << endl;
  return 0;
}