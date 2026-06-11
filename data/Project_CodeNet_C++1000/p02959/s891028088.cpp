#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n;
  cin >> n;
  vector<ll> m(n+1);
  vector<ll> h(n);
  rep(i, n+1) {
    cin >> m[i];
  }
  rep(i, n) {
    cin >> h[i];
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += min(h[i], m[i]);
    if (h[i] > m[i]) {
      ll r = h[i] - m[i];
      if (m[i+1] > r) {
        ans += r;
        m[i+1] -= r;
      } else {
        ans += m[i+1];
        m[i+1] = 0; 
      }
    }
  }
  cout << ans << endl;
  return 0;
}