#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <string>
#include <utility>
#include <cassert>
#include <numeric>
#include <random>


using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll p, q, r;
  cin >> p >> q >> r;
  ll res = min(p+q, q +r);
  res = min(res, r+p);
  cout << res << endl;

  return 0;
}
