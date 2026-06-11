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
typedef unsigned long long ull;

int main(void) {
  string s;
  cin >> s;
  int n = s.size() + 1;
  vector<ull> left(n, 0), right(n, 0);
  for (int i = 1; i <= n - 1; i++) {
    if (s.at(i - 1) == '<') left.at(i) = left.at(i - 1) + 1;
  }
  for (int i = n - 2; i >= 0; i--) {
    if (s.at(i) == '>') right.at(i) = right.at(i + 1) + 1;
  }
  vector<ull> mx(n);
  ull ans = 0;
  rep(i, n) {
    mx.at(i) = max(left.at(i), right.at(i));
    ans += mx.at(i);
  }

  cout << ans << endl;

  return 0;
}
