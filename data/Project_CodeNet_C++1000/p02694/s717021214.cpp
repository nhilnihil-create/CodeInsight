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
  ll x;
  cin >> x;
  ll res = 100;
  int ans = 0;
  while (true) {
    res = res + res / 100;
    ans++;
    if (x <= res) break;
  }
  cout << ans << endl;
  return 0;
}