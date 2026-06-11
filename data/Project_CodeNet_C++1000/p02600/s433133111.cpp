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
  int x;
  cin >> x;
  int ans = 8;
  if (1800 <= x) {
    ans = 1;
  } else if (1600 <= x) {
    ans = 2;
  } else if (1400 <= x) {
    ans = 3;
  } else if (1200 <= x) {
    ans = 4;
  } else if (1000 <= x) {
    ans = 5;
  } else if (800 <= x) {
    ans = 6;
  } else if (600 <= x) {
    ans = 7;
  }
  cout << ans << endl;
  return 0;
}