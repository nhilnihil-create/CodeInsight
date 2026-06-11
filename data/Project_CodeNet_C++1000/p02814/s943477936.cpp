#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ll>;
#define INF 1000000000
#define LLINF 10000000000000000ll
#define MOD 1000000007LL

bool dbgflag = false;

ll gcd(ll a, ll b) {
  //cout << "gcd" << a << b << endl;
  if (a < b) swap(a, b);
  if (a % b == 0) return b;
  a %= b;
  return gcd(b, a);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  ll ming = 1;
  ll twopow = 1;
  ll ac = a[0];
  while (a[0] % 2 == 0) {
    a[0] /= 2;
    twopow *= 2;
  }
  ming *= ac / 2;
  if (ming > m) {
    cout << 0 << endl;
    return 0;
  }

  for (int i = 1; i < n; i++) {
    ac = a[i];
    if (a[i] % twopow != 0) {
      cout << 0 << endl;
      return 0;
    }
    a[i] /= twopow;
    if (a[i] % 2 == 0) {
      cout << 0 << endl;
      return 0;
    }
    //以下2で割れる回数は同じことが保証される
    ming = (ming *  (ac / 2)) / gcd(ming, ac / 2);
    if (ming > m) {
      cout << 0 << endl;
      return 0;
    }
  }

  //cout << ming << endl;

  cout << 1 + ((m - ming) / (2 * ming)) << endl;
}