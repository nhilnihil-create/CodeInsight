#include <bits/stdc++.h>
#define IOS                                                                    \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
ll MOD = 1'000'000'007;
ll bpow(ll b, ll p, ll m = 1000000007LL) {
  ll rt = 1;
  for (; p; p >>= 1, b = b * b % m)
    if (p & 1)
      rt = rt * b % m;
  return rt;
}
int main() {
  IOS;
  ll n, k;
  cin >> n >> k;
  ll sum1 = 0, sum2 = 0;
  ll ans = 0;
  for (int i = 0; i < n + 1; i++) {
    sum1 += i, sum2 += n - i;
    if (i >= k - 1)
      ans = (ans + (sum2 - sum1 + 1)) % MOD;
  }
  cout << ans << endl;
}