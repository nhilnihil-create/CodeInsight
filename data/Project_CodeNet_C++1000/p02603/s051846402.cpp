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
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  ll total = 1000;
  for (int i = 0; i + 1 < n; ++i) {
    if (a[i] < a[i + 1]) {
      ll t = total / a[i];
      total -= a[i] * t;
      total += a[i + 1] * t;
    }
  }
  cout << total << endl;
  return 0;
}