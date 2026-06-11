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
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  double sum = 0.0;
  for (int i = 0; i < n; ++i) {
    sum += (1.0 / (1.0 * a[i]));
  }
  printf("%.10f\n", 1.0 / sum);
  return 0;
}