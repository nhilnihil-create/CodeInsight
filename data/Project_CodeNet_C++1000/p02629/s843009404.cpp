#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
const int INF = 1000000009;
const ll LINF = 1e18;

int main() {
  ll n; cin >> n;
  string res = "";
  while (n) {
    --n;
    res += 'a' + (n % 26);
    n /= 26;
  }
  reverse(res.begin(), res.end());
  cout << res << endl;
}
