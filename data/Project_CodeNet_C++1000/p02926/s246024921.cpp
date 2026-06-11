#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <cfloat>
#include <complex>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

int main() {
  ll N;

  cin >> N;

  vector<pair<double, P> > lst;
  for (int i = 0; i < N; i++) {
    ll x, y;
    cin >> x >> y;
    double xd = x;
    double yd = y;
    if (x == 0 && y == 0) continue;

    double theta = atan2(yd, xd);
    // cout << theta << endl;
    lst.emplace_back(pair<double, P>(theta, P(x, y)));
  }

  sort(lst.begin(), lst.end());

  ll ans = 0.0;
  for (size_t i = 0; i < lst.size(); i++) {
    for (size_t j = 0; j < lst.size(); j++) {
      ll tmpx = 0, tmpy = 0;
      for (size_t k = i; k <= i + j; k++) {
        tmpx += lst[k % lst.size()].second.first;
        tmpy += lst[k % lst.size()].second.second;
      } // k
      ans = max(ans, tmpx * tmpx + tmpy * tmpy);
    }  // j
  } // i

  printf("%.15f\n", sqrt((double)ans));

  return 0;
}