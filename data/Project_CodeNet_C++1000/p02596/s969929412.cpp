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
  int k;
  cin >> k;
  int now = 0;
  for (int i = 0; i < k; ++i) {
    now = (((now * 10) % k) + (7 % k)) % k;
    if (now == 0) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}