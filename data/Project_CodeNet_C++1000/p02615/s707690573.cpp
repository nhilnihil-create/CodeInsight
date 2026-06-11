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
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end(), greater<ll>());
  
  ll sum = 0;
  int t = n - 1;
  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      sum = a[0];
      --t;
      if (t == 0) {
        cout << sum << endl;
        return 0;
      }
    } else {
      for (int j = 0; j < 2; ++j) {
        --t;
        sum += a[i];
        if (t == 0) {
          cout << sum << endl;
          return 0;
        }
      }
    }
  }
}
