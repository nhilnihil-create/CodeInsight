#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>

using namespace std;

typedef long long ll;


int main()
{
  int n;
  cin >> n;
  vector<ll> a(n), s(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  s[0] = a[0];
  for (int i = 1; i < n; ++i) s[i] = s[i - 1] + a[i];

  ll result = s[n - 1];
  for (int i = 0; i < n; ++i) {
    ll l = s[i];
    ll r = s[n - 1] - s[i];
    result = min<ll>(result, abs(l - r));
  }
  cout << result << endl;
  return 0;
}
