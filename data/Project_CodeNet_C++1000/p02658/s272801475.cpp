#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  sort(a.begin(), a.end());
  ll ans = 1;
  rep(i, n) {
    if(a[i] == 0) {
      ans = 0;
      break;
    } else if(a[i] > (ll)1e18 / ans) {
      ans = -1;
      break;
    } else {
      ans *= a[i];
    }
  }
  cout << ans << endl;
  return 0;
}