#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  map<ll, bool> mp;
  ll a;
  bool ok = true;
  rep(i, n) {
    cin >> a;
    if (mp[a]) {
      ok = false;
    }
    mp[a] = true;
  }
  if (ok) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
