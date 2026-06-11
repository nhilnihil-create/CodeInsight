#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;
  ll MOD = 998244353;
  ll ans = 1;
  ll M = 0;
  map<int,int> dist;

  bool b = false;
  for (ll i = 0; i < N; i++) {
    ll e;
    cin >> e;
    M = max(M,e);
    if (i == 0 && e != 0) b = !b;
    dist[e] += 1;
  }
  if (dist[0] != 1) b = !b;
  
  if (b) {
    cout << 0 << endl;
    return 0;
  }
  
  for (ll i = 0; i < M; i++) {
    if (!dist.count(i)) {
      cout << 0 << endl;
      return 0;
    }
    for (int j = 0; j < dist[i+1]; j++) {
      ans *= dist[i];
      ans %= MOD;
    }
    ans %= MOD;
  }

  cout << ans << endl;
}