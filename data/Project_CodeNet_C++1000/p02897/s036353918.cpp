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

using namespace std;
typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int odd = (n + 1) / 2;
  double res = odd / (1.0 * n);
  cout << setprecision(9) << fixed << res << endl;
  return 0;
}
