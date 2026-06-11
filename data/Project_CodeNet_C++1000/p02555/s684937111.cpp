#include <math.h>
#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

constexpr long long INFLL = 1e18;
constexpr long long aPN = 1e9 + 7;

using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll s;
  cin >> s;

  vector<ll> v(s + 1);
  v.at(0) = 1;

  for (ll i = 2; i <= s; i++) {
    for (ll k = i - 3; k >= 0; k--) {
      v.at(i) += v.at(k);
      v.at(i) %= aPN;
    }
  }
  cout << v.at(s) << endl;

  return 0;
}