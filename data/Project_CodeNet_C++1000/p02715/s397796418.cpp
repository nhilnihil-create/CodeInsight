#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ll>;
#define INF 1000000
#define LLINF 10000000000000000ll
#define MOD 1000000007LL

bool dbgflag = false;

ll modPow(ll a, ll n, ll p) {
  if (n == 1) return a % p;
  if (n % 2 == 1) return (a * modPow(a, n-1, p)) % p;
  ll t = modPow(a, n/2, p);
  return (t * t) % p;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, k;
  cin >> n >> k;
  vector<ll> rec(k);
  for (int i = k; i > 0; i--) {
    ll cnt = modPow(k / i, n, MOD);
    //cout << cnt << endl;
    for (int j = i*2; j <= k; j+=i) {
      cnt -= rec[j-1];
    }
    cnt = (cnt + 10000LL*MOD) % MOD;
    rec[i-1] = cnt;
  }
  ll ans = 0;
  for (int i = 0; i < k; i++) {
    //cout << rec[i] << " ";
    ans += (i+1) * rec[i];
    ans %= MOD;
  }
  cout << ans << endl;
}