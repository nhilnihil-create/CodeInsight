#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  rep(i, n) cin >> h[i];
  if(n <= k) cout << 0 << endl;
  else {
    sort(h.begin(), h.end());
    rep(i, k) {
      h.pop_back();
    }
    ll ans = 0;
    rep(i, h.size()) ans+=h[i];
    cout << ans << endl;
  }
  return 0;
}