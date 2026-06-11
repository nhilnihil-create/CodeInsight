#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  ll ans = 1000;
  rep(i,n-1) {
    if (a[i] <= a[i+1]) {
      ll s = ans / a[i];
      ans += (a[i+1] - a[i]) * s;
    }
  }
  cout << ans << endl;
  return 0;
}