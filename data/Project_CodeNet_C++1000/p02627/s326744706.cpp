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
  char alpha;
  cin >> alpha;
  if (alpha >= 'A' && alpha <= 'Z') {
    cout << "A\n";
  } else {
    cout << "a\n";
  }
}
