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
const int INF = 1000000009;
const ll LINF = 1e18;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int sum = 0;
  for (int i = 0; i < n; ++i) sum ^= a[i];
  for (int i = 0; i < n; ++i) a[i] ^= sum;
  for (int i = 0; i < n; ++i) cout << a[i] << endl;
}
