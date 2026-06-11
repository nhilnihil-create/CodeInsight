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
  int ans = 0;
  int t = x / 500;
  ans += t * 1000;
  x -= t * 500;
  t = x / 5;
  ans += t * 5;
  cout << ans << endl;
  return 0;
}