#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<int> r(n);
  ll sum = 0;
  rep(i, n) {
    if (i % 2 == 0) sum += a[i];
    else sum -= a[i];
  }
  r[0] = sum;
  for (int i = 1; i < n; ++i) {
    sum = -sum + 2 * a[i-1];
    r[i] = sum;
  }
  rep(i, n-1) printf("%d ", r[i]);
  printf("%d\n", r[n-1]);
  return 0;
}