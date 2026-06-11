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
using pii = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
ll bpow(ll b, ll p, ll m = 1000000007LL) {
  ll rt = 1;
  for (; p; p >>= 1, b = b * b % m)
    if (p & 1)
      rt = rt * b % m;
  return rt;
}
int p[105];
int main() {
  IOS;
  int x, n;
  cin >> x >> n;
  for (int i = 0; i < n; i++)
    cin >> p[i];
  int mn = 1e9, ans = -1;
  for (int i = -105; i <= 105; i++) {
    int ok = 1;
    for (int j = 0; j < n; j++)
      if (p[j] == i)
        ok = 0;
    if (ok && abs(i - x) < mn)
      mn = abs(i - x), ans = i;
  }
  cout << ans << endl;
}
