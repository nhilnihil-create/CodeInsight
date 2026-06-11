#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  ll total;
  ll m1 = 0;
  total = accumulate(a.begin(), a.end(), 0);
  for (int i=0; i<n; i=i+2) {
    m1 += 2 * a[i];
  }
  m1 -= total;
  vector<int> ans(n);
  ans[0] = m1;
  for (int i=1; i<n; i++){
    ans[i] = 2 * (a[i-1] - ans[i-1] / 2);
  }
  rep(i,n) printf("%d%c", ans[i], i==n-1?'\n':' ');
  return 0;
}
