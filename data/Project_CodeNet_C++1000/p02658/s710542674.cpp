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
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;
using ll = long long;
const int INF = 1000000009;
const ll LINF = 1e18;

int main() {
  int n;
  cin >> n;
  cpp_int rtn = 1;
  vector<cpp_int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] == 0) {
      cout << "0\n";
      return 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    rtn *= a[i];
    if (rtn > LINF) {
      cout << "-1\n";
      return 0;
    }
  }
  cout << rtn << endl;
}
