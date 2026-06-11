#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  string s;
  ll k;
  cin >> s >> k;
  ll n = s.length();
  if (n == 1) {
    cout << k / 2 << endl;
    return 0;
  }
  ll l = 0, r = 0;
  for (int i = 0; i < n; i++) {
    if (s[0] == s[i]) {
      l++;
    } else {
      break;
    }
  }
  if (l == n) {
    cout << n * k / 2 << endl;
    return 0;
  }
  for (int i = n - 1; i >= 0; i--) {
    if (s[n - 1] == s[i]) {
      r++;
    } else {
      break;
    }
  }
  if (l + r == n) {
    ll ans = l / 2 * k + r / 2 * k;
    cout << ans << endl;
    return 0;
  }
  ll ans = 0;
  ll c = 1;
  for (int i = l; i < n - r; i++) {
    if (s[i] == s[i + 1]) {
      c++;
    } else {
      ans += c / 2 * k;
      c = 1;
    }
  }
  ans += c / 2 * (k - 1);
  if (s[0] == s[n - 1]) {
    ans += l / 2 + (l + r) / 2 * (k - 1) + r / 2;
  } else {
    ans += l / 2 * k + r / 2 * k;
  }
  cout << ans << endl;
  return 0;
}