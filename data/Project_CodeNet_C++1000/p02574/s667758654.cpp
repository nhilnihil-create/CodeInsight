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
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const ll MOD = 1000000007LL;
ll bpow(ll b, ll p, ll m = 1000000007LL) {
  ll rt = 1;
  for (; p; p >>= 1, b = b * b % m)
    if (p & 1)
      rt = rt * b % m;
  return rt;
}
int a[1000005];
int sieve[1000005];
vector<int> prime;
int h[1000005];
int check(int x) {
  int tmp = sieve[x];
  while (x != 1) {
    tmp = sieve[x];
    if (x % tmp == 0 && h[tmp] > 1)
      return 0;
    while (x % tmp == 0)
      x /= tmp;
  }
  return 1;
}
void fact(int x) {
  int tmp = sieve[x];
  while (x != 1) {
    tmp = sieve[x];
    if (x % tmp == 0)
      h[tmp]++, x /= sieve[x];
    while (x % tmp == 0)
      x /= tmp;
  }
}
int main() {
  IOS;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int g = a[1];
  for (int i = 2; i <= n; i++) {
    g = __gcd(g, a[i]);
  }
  for (int i = 1; i <= 1000000; i++)
    sieve[i] = (i & 1 ? i : 2);
  for (int i = 3; i <= 1000000; i++) {
    if (sieve[i] == i)
      for (int j = i; j <= 1000000; j += i) {
        if (sieve[j] == j)
          sieve[j] = i;
      }
  }
  for (int i = 1; i <= n; i++) {
    fact(a[i]);
  }
  int ok = 1;
  for (int i = 1; i <= n; i++) {
    if (!check(a[i]))
      ok = 0;
  }
  if (ok) {
    cout << "pairwise coprime" << endl;
  } else if (!ok && g == 1) {
    cout << "setwise coprime" << endl;
  } else if (!ok) {
    cout << "not coprime" << endl;
  }
}
