#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  rep(i, n) --a[i];
  vector<int> b(n);
  rep(i, n) cin >> b[i];
  vector<int> c(n-1);
  rep(i, n-1) cin >> c[i];
  int ans = 0;
  rep(i, n) {
    ans += b[a[i]];
    if (i < n-1 && (a[i] + 1 == a[i+1])) {
      ans += c[a[i]];
    }
    //cout << ans << '\n';
  }
  cout << ans << '\n';
  
  return 0;
}