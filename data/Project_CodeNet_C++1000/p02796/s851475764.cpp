#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<pair<ll, ll>> s(n);
  for (int i = 0; i < n; ++i) {
    ll x, d;
    cin >> x >> d;
    s[i].first = x - d;
    s[i].second = x + d;
  }
  sort(s.begin(), s.end(), [](pair<ll, ll> a, pair<ll, ll> b) { return a.second < b.second; });
  int result = 0;
  ll last = -ll(1e10);
  for (auto p : s) if (p.first >= last) {
    result++;
    last = p.second;
  }
  cout << result << endl;

  return 0;
}
