#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
#include <sstream>
#include <fstream>
#include <climits>
#include <map>
#include <numeric>
#include <functional>
#include <utility>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int main(void) {
  string s;
  cin >> s;
  ll k;
  cin >> k;
  vector<ll> v;
  ll seq = 1;
  for (int i = 1; i < s.size(); i++) {
    if (s.at(i) == s.at(i - 1)) {
      seq++;
    }
    else {
      v.push_back(seq);
      seq = 1;
    }
  }
  v.push_back(seq);

  ll ans = 0;
  if (s.front() == s.back()) {
    if (v.size() == 1) {
      ans = (v.at(0) * k) / 2;
    }
    else {
      for (int i = 0; i < v.size(); i++) {
        if (i == 0 || i == v.size() - 1) ans += v.at(i) / 2;
        else ans += (v.at(i) / 2) * k;
      }
      ans += ((v.front() + v.back()) / 2) * (k - 1);
    }
  }
  else {
    for (auto el : v) {
      ans += (el / 2) * k;
    }
  }
  cout << ans << endl;

  return 0;
}
