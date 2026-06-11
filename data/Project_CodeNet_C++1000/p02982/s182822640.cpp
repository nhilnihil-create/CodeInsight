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
  int n, d;
  cin >> n >> d;
  vector<vector<int> > x(n, vector<int>(d));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < d; ++j) {
      cin >> x[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int dist = 0;
      for (int k = 0; k < d; ++k) {
        dist += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
      }
      bool ok = false;
      for (int k = 1; k <= 300; ++k) {
        if (dist == k * k) ok = true;
      }
      if (ok) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}