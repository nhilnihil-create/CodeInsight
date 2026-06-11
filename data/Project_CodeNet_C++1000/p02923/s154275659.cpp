#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i, n) cin >> h[i];
  int now = 0;
  int ans = now;
  for (int i = 1; i < n; ++i) {
    if (h[i] <= h[i-1]) ++now;
    else now = 0;
    ans = max(ans, now);
  }
  cout << ans << endl;
  return 0;
}