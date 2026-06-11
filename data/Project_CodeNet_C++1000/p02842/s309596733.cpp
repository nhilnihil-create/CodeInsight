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
  for (int x = 1; x <= n; ++x) {
    int res = x * 1.08;
    if (res == n) {
      cout << x << endl;
      return 0;
    }
  }
  cout << ":(" << endl;
  return 0;
}