#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  ll len = 0;
  rep(i,n) {
    cin >> a[i];
    len += a[i];
  }
  ll hal=0, ans=len;
  rep(i,n) {
    hal += a[i];
    ans = min(ans, abs(hal-(len-hal)));
  }
  cout << ans << endl;
  return 0;
}