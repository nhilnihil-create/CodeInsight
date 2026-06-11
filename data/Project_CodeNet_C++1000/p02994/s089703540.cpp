#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i, s, n) for (int i = (s); i < (n); ++i)
#define rrep(i, n, g) for (int i = (n)-1; i >= (g); --i)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define len(x) (int)(x).size()
#define dup(x, y) (((x) + (y)-1) / (y))
#define pb push_back
#define Field(T) vector<vector<T>>
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, l;
  cin >> n >> l;
  ll a[n], ans = 0;
  rep(i, 0, n) {
    a[i] = i + l;
    ans += a[i];
  }
  if (-1 * n >= l)
    ans -= a[n - 1];
  else if (l > 0)
    ans -= a[0];
  cout << ans << endl;
  return 0;
}