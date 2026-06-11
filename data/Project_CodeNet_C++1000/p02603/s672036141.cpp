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
  vector<ll> vec;
  vec.push_back(a[0]);
  for (int i = 1; i < n; ++i) {
    if (vec.back() == a[i]) continue;
    vec.push_back(a[i]);
  }
  ll total = 1000, cnt = 0;
  for (int i = 0; i + 1 < vec.size(); ++i) {
    if (vec[i] < vec[i + 1]) {
      cnt = total / vec[i];
      total -= vec[i] * cnt;
      total += vec[i + 1] * cnt;
      cnt = 0;
    }
  }
  cout << total << endl;
  return 0;
}