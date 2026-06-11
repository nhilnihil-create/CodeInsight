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
  map<ll, ll> mp1, mp2;
  for (int i = 0; i < n; ++i) {
    mp1[a[i] + (i + 1)]++;
    mp2[(i + 1) - a[i]]++;
  }
  ll ans = 0;
  for (auto a : mp1) {
    ans += a.second * mp2[a.first];
  }
  cout << ans << endl;
  return 0;
}