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
  ll n, p;
  cin >> n >> p;
  string s;
  cin >> s;
  if (p == 2 || p == 5) {
    ll result = 0;
    ll cur = 0;
    for (char c : s) {
      cur++;
      ll x = c - '0';
      if (x % p == 0) result += cur;
    }
    cout << result << endl;
    return 0;
  }

  reverse(s.begin(), s.end());
  vector<ll> a = {0};
  ll d = 1;
  for (char c : s) {
    ll x = c - '0';
    a.push_back(x * d % p);
    d = d * 10 % p;
  }

  for (ll i = 0; i < a.size() - 1; ++i) {
    a[i + 1] += a[i];
    a[i + 1] %= p;
  }

  vector<ll> count(p);
  ll result = 0;
  for (ll x : a) {
    result += count[x];
    count[x]++;
  }

  cout << result << endl;

  return 0;
}
