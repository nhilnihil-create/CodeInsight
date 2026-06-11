#include <bits/stdc++.h>
#define IOS                                                                    \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define repl(i, a, b) for (ll i = a; i < (b); ++i)
#define repd(i, a, b) for (int i = b; i >= (a); --i)
#define repdl(i, a, b) for (ll i = b; i >= (a); --i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const ll MOD = 1'000'000'007LL;
ll bpow(ll b, ll p, ll m = 1000000007LL) {
  ll rt = 1;
  for (; p; p >>= 1, b = b * b % m)
    if (p & 1)
      rt = rt * b % m;
  return rt;
}
int a[1000005];
int sieve[1000005];
int cnt[1000005];
void fact(int x) {
  if (x == 1)
    return;
  while (x != 1) {
    int tmp = sieve[x];
    cnt[tmp]++;
    while (x % tmp == 0)
      x /= tmp;
  }
}
bool check(int x) {
  if (x == 1)
    return true;
  while (x != 1) {
    int tmp = sieve[x];
    if (cnt[tmp] > 1)
      return false;
    while (x % tmp == 0)
      x /= tmp;
  }
  return true;
}
int main() {
  IOS;
  int n;
  cin >> n;
  for (int i = 1; i < 1000005; i++)
    sieve[i] = i;
  for (int i = 2; i < 1000005; i += 2)
    sieve[i] = 2;
  for (int i = 3; i < 1000005; i++) {
    if (sieve[i] == i) {
      for (ll j = 1LL * i * i; j < 1000005; j += i) {
        sieve[j] = i;
      }
    }
  }
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  int g = 0;
  for (int i = 1; i <= n; i++) {
    g = __gcd(g, a[i]);
    fact(a[i]);
  }
  int ok = 1;
  for (int i = 1; i <= n; i++) {
    if (!check(a[i]))
      ok = 0;
  }
  if (ok) {
    cout << "pairwise coprime" << endl;
  } else if (g == 1) {
    cout << "setwise coprime" << endl;
  } else {
    cout << "not coprime" << endl;
  }
}
