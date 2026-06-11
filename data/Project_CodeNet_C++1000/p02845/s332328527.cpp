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
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  ll ans = 1;
  vector<ll> num(3);
  for (int i = 0; i < n; ++i) {
    int cnt = 0;
    for (int j = 0; j < 3; ++j) {
      if (num[j] == a[i]) cnt++;
    }
    ans *= cnt;
    ans %= MOD;
    for (int j = 0; j < 3; ++j) {
      if (num[j] == a[i]) {
        num[j]++;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}