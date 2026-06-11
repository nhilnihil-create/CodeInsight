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
  int x, y;
  cin >> x >> y;
  int ans1 = 0, ans2 = 0;
  if (x == 3) {
    ans1 = 100000;
  } else if (x == 2) {
    ans1 = 200000;
  } else if (x == 1) {
    ans1 = 300000;
  }
  if (y == 3) {
    ans2 = 100000;
  } else if (y == 2) {
    ans2 = 200000;
  } else if (y == 1) {
    ans2 = 300000;
  }
  int ans = ans1 + ans2;
  if (x == 1 && y == 1) {
    ans += 400000;
  }
  cout << ans << endl;
  return 0;
}