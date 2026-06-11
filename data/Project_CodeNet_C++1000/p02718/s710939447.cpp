#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    int inp;
    cin >> inp;
    a[i] = inp;
    sum += inp;
  }
  int cnt = 0;
  for (int i = 0; i < n; ++i)
    if (4 * m * a[i] >= sum) ++cnt;

  if (cnt >= m)
    cout << "Yes\n";
  else
    cout << "No\n";
}
