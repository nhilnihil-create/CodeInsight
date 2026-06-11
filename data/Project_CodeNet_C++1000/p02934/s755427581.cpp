#include <iterator>
#include <list>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <numeric>
using namespace std;

int main() {
  int N; cin >> N;
  double ans = 0;

  for (int i = 1; i <= N; i++) {
    double d; cin >> d;
    ans += 1 / d;
  }
  cout << fixed << setprecision(9) << 1 / ans << endl;
  return 0;
}
