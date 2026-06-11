#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

const ll M = 1e9+7;
const ll INF = 1e9+7;

ll n, ans;
ll cnt[100];

int main() {
  cin >> n;

  for (ll i = 0; i < n; i++) {
    ll a;
    cin >> a;
    for (ll j = 0; j < 64; ++j) {
      if ((a >> j) & 1) cnt[j]++;
    }
  }
  
  for (ll i = 0; i < 64; i++) {
    ans += cnt[i] * (n-cnt[i]) % M * ((1LL << i) % M);
    ans %= M;
  }
  
  cout << ans << endl;
  return 0;
}