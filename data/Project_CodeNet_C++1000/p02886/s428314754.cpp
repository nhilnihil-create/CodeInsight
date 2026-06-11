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
  vector<int> d(n);
  for (int i = 0; i < n; ++i) {
    cin >> d[i];
  }
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += d[i];
  }
  int ans = sum * sum;
  for (int i = 0; i < n; ++i) {
    ans -= d[i] * d[i];
  }
  ans /= 2;
  cout << ans << endl;
  return 0;
}