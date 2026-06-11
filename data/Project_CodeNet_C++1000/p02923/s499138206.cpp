#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  // ダブリング
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i, n) cin >> h[i];
  vector<int> next(n);
  next[n-1] = n-1;
  rep(i, n-1) {
    if (h[i] >= h[i+1]) next[i] = i+1;
    else next[i] = i;
  }
  rep(i, 20) {
    vector<int> prev = next;
    rep(j, n) next[j] = prev[next[j]];
  }
  int ans = 0;
  rep(i, n) {
    int temp = next[i] - i;
    if (temp > ans) ans = temp;    
  }
  cout << ans << '\n';
  return 0;
}
