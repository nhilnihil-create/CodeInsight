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
  int a, b;
  cin >> a >> b;
  for (int x = 1; x <= 100000; ++x) {
    int c = x * 0.08;
    int d = x * 0.10;
    if (c == a && d == b) {
      cout << x << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}