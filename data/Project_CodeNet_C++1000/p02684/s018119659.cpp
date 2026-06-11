#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> p;
typedef long long ll;
const int inf = 1000000007;

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) {
    cin >> a[i];
    a[i]--;
  }
  ll sid = 0;
  vector<ll> sumi(n, -1);
  vector<ll> s;
  ll beg = 0;
  ll t = 0;
  sumi[0] = 0;
  s.push_back(0);
  // cout << beg << ", ";
  for (ll i = 1; i < n; i++) {
    beg = a[beg];
    // cout << beg << ", ";
    if (sumi[beg] == -1) {
      sumi[beg] = i;
      s.push_back(beg);
    } else {
      t = i - sumi[beg];
      sid = sumi[beg];
      break;
    }
  }
  // cout << endl;
  // cout << sid << ", " << t << endl;
  ll ans = 0;
  if (k <= sid) {
    // rep(i, k) { ans = a[ans]; }
    cout << s[k] + 1 << endl;
    return 0;
  }
  ll id = (k - sid) % t;
  // rep(i, sid + id) { ans = a[ans]; }
  cout << s[sid + id] + 1 << endl;
  return 0;
}