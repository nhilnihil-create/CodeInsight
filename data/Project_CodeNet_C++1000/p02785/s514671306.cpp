#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using ld = long double;
#define ALL(x) x.begin(),x.end()
#define P pair<int,int>
#define mod 1000000007

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  rep(i, n) {
    cin >> h[i];
  }
  sort(h.rbegin(), h.rend());
  if (k > 0) {
    h.erase(h.begin(), h.begin() + min(k, n));
  }
  ll ans = 0;
  rep(i, h.size()) {
    ans += h[i];
  }
  cout << ans << endl;

  return 0;
}
