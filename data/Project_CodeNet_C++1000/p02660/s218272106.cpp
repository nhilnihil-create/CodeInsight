/*input
997764507000
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n;
  cin >> n;
  const ll M = 1e6+5;
  vector<int> used(M);
  ll ans = 0;
  for (int i = 2; i < M; ++i) {
    if (used[i]) continue;
    ll mod = i;
    while (mod < M && n%mod == 0) {
      ans++;
      n /= mod;
      used[mod] = 1;
      mod *= i;
    }
    while (n%i == 0) n /= i;
  }
  if (n > 1) ans++;
  cout << ans << endl;
}