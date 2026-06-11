#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const ll M = 1e9+7;
const ll INF = 1e9+7;

ll n, t, ans;
P p[3100];
ll dp[3100];

int main() {
  cin >> n >> t;

  for (ll i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
  }
  
  sort(p, p+n);
  
  for (ll i = 0; i < n; i++) {
    ll a = p[i].first, b = p[i].second;
    for (ll j = 3000; j >= 0; j--) {
      if (j + a >= t) {
        ans = max(ans, dp[j]+b);
      } else {
        dp[j+a] = max(dp[j+a], dp[j]+b);
      }
    }
  }
  
  for (ll i = 0; i < t; i++) {
    ans = max(ans, dp[i]);
  }
  
  cout << ans << endl;
  return 0;
}