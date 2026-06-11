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
  vector<int> p(n), q(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> q[i];
  }
  vector<int> order(n);
  for (int i = 0; i < n; ++i) {
    order[i] = i + 1;
  }
  int a = 0, b = 0;
  int cnt = 0;
  do {
    cnt++;
    if (order == p) a = cnt;
    if (order == q) b = cnt;
  } while (next_permutation(order.begin(), order.end()));
  cout << abs(a - b) << endl;
  return 0;
}