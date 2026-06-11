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
  ll ans = 1, sub1 = 1, sub2 = 1;
  for (int i = 0; i < n; ++i) {
    ans = (ans * 10) % MOD;
    sub1 = (sub1 * 9) % MOD;
    sub2 = (sub2 * 8) % MOD;
  }
  ll sub = (sub1 + sub1) % MOD;
  sub = (sub + MOD - sub2) % MOD;
  ans = (ans + MOD - sub) % MOD;
  cout << ans << endl;
  return 0;
}