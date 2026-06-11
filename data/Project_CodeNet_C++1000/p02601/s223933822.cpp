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
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  while (k && a >= b) {
    b *= 2;
    k--;
  }
  while (k && b >= c) {
    c *= 2;
    k--;
  }
  cout << ((a < b && b < c) ? "Yes" : "No") << endl;
  return 0;
}