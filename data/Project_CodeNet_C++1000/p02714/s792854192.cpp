#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  ll r = 0, g = 0, b = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'R') r++;
    if (s[i] == 'G') g++;
    if (s[i] == 'B') b++;
  }
  ll ans = r * g * b;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int k = 2 * j - i;
      if (j < k && k < n && s[i] != s[j] && s[i] != s[k] && s[j] != s[k]) {
        ans--;
      }
    }
  }
  cout << ans << endl;
  return 0;
}